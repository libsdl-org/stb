/* https://github.com/nothings/stb/pull/1557 */
/* build with ASAN,
   run with an instruction that allocator may fail (otherwise ASAN will quit early
   with AddressSanitizer: requested allocation size ... exceeds maximum supported size):
   ASAN_OPTIONS=allocator_may_return_null=1 <program name>

AddressSanitizer:DEADLYSIGNAL
=================================================================
==217447==ERROR: AddressSanitizer: SEGV on unknown address (pc 0x00000041f6d4 bp 0x000000000000 sp 0x7ffd3e146c60 T0)
==217447==The signal is caused by a READ memory access.
    #0 0x41f6d4 in atomic_compare_exchange_strong<__sanitizer::atomic_uint8_t> /src/llvm-project/compiler-rt/lib/asan/../sanitizer_common/sanitizer_atomic_clang.h:81:10
    #1 0x41f6d4 in AtomicallySetQuarantineFlagIfAllocated /src/llvm-project/compiler-rt/lib/asan/asan_allocator.cpp:610:10
    #2 0x41f6d4 in __asan::Allocator::Deallocate(void*, unsigned long, unsigned long, __sanitizer::BufferedStackTrace*, __asan::AllocType) /src/llvm-project/compiler-rt/lib/asan/asan_allocator.cpp:685:10
    #3 0x49e5d5 in free /src/llvm-project/compiler-rt/lib/asan/asan_malloc_linux.cpp:53:3
    #4 0x4dcedb in setup_free(stb_vorbis*, void*) tests/../stb_vorbis.c:966:4
    #5 0x4dbe57 in vorbis_deinit(stb_vorbis*) tests/../stb_vorbis.c:4214:7
    #6 0x4f9638 in stb_vorbis_open_memory tests/../stb_vorbis.c:5122:4
    #7 0x4fbfb1 in stb_vorbis_decode_memory tests/../stb_vorbis.c:5390:20
*/
#include "../stb_vorbis.c"
#include <stdint.h>

int main(int argc, char* argv[])
{
    const uint8_t data[] = {0x4f,0x67,0x67,0x53,0x00,0x7a,0x18,0xfe,0xa9,0x00,0x53,
                            0x00,0xe3,0xb5,0x21,0x68,0x00,0x00,0x00,0x00,0x00,0x00,
                            0x6b,0x0e,0xa0,0x75,0x01,0x1e,0x01,0x76,0x6f,0x72,0x62,
                            0x69,0x73,0x00,0x00,0x00,0x00,0x01,0xfb,0x07,0xae,0x69,
                            0x73,0x00,0x00,0x00,0x00,0x2e,0x09,0x3c,0xff,0x30,0x00,
                            0x01,0xa9,0xf9,0x4f,0x67,0x67,0x53,0x00,0x00,0x00,0x7e,
                            0x79,0x6f,0x42,0x0c,0xc5,0x97,0x21,0x68,0x00,0x00,0x01,
                            0x00,0x00,0x00,0x6f,0x11,0x00,0x00,0x00,0x03,0x76,0x6f,
                            0x72,0x62,0x69,0x73,0x00,0x00,0x00,0x00,0x2e};
    size_t size = sizeof(data);

    int chan, samplerate;
    short *output;
    int samples = stb_vorbis_decode_memory(data, size, &chan, &samplerate, &output);
    if (samples >= 0)
        free(output);
    return 0;
}
