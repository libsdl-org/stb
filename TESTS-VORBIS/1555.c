/* https://github.com/nothings/stb/pull/1555 */
/* build with ASAN.

AddressSanitizer:DEADLYSIGNAL
=================================================================
==302322==ERROR: AddressSanitizer: SEGV on unknown address 0x7f70bd3697ff (pc 0x0000004e41f4 bp 0x7ffc029b3070 sp 0x7ffc029b0be0 T0)
==302322==The signal is caused by a WRITE memory access.
    #0 0x4e41f4 in start_decoder(stb_vorbis*) tests/../stb_vorbis.c:3658:19
    #1 0x4f9444 in stb_vorbis_open_memory tests/../stb_vorbis.c:5112:8
    #2 0x4fd8e9 in main tests/stb_vorbis_fuzzer.c:24:23
*/
#include "../stb_vorbis.c"
#include <stdint.h>

int main(int argc, char* argv[])
{
    const uint8_t data[] = {0x4f,0x67,0x67,0x53,0x00,0x02,0xac,0xf4,0x30,
                            0x19,0x50,0x13,0x00,0x68,0x00,0x00,0x00,0x21,
                            0x00,0x40,0x00,0x00,0x00,0x7e,0x84,0x04,0x01,
                            0x1e,0x01,0x76,0x6f,0x72,0x62,0x69,0x73,0x00,
                            0x00,0x00,0x00,0x05,0x00,0x45,0xc5,0x87,0x03,
                            0x00,0x04,0x00,0x02,0x00,0x08,0x00,0x00,0x01,
                            0x00,0x2e,0xa9,0xcb,0x4f,0x67,0x67,0x53,0x00,
                            0x28,0x00,0x00,0xf7,0xff,0xff,0x7f,0x68,0x00,
                            0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x76,0x6f,
                            0x72,0x73,0x00,0x00,0x03,0x76,0x6f,0x72,0x62,
                            0x69,0x73,0xff,0xff,0xff,0xee};
    size_t size = sizeof(data);

    stb_vorbis_alloc alloc;
    int alloc_buffer_length = 600 * 1024;
    alloc.alloc_buffer = (char*)malloc(alloc_buffer_length);
    alloc.alloc_buffer_length_in_bytes = alloc_buffer_length;
    int err;
    stb_vorbis* out = stb_vorbis_open_memory(data, size, &err, &alloc);
    stb_vorbis_close(out);
    free(alloc.alloc_buffer);
    return 0;
}
