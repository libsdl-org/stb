/* https://github.com/nothings/stb/issues/1537 */
/* build with UBSAN, run with UBSAN_OPTIONS=silence_unsigned_overflow=1 <program name>

/src/stb/tests/../stb_vorbis.c:5285:21: runtime error: signed integer overflow: -1025582044 - 1136656384 cannot be represented in type 'int'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /src/stb/tests/../stb_vorbis.c:5285:21 in
 */
#include "../stb_vorbis.c"
#include <stdint.h>

int main(int argc, char* argv[])
{
    const uint8_t data[] = {0x4f,0x67,0x67,0x53,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa9,0x6e,0x22,0x52,0x00,0x00,
                            0x00,0x00,0x6b,0x8f,0xfb,0xa0,0x01,0x1e,0x01,0x76,0x6f,0x72,0x62,0x69,0x73,0x00,0x00,0x00,0x00,0x06,
                            0x80,0xbb,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x7e,0x05,0x00,0x00,0x00,0x00,0x00,0xb8,0x01,0x4f,0x67,
                            0x67,0x53,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa9,0x6e,0x22,0x52,0x01,0x00,0x00,0x00,
                            0x7a,0x28,0x76,0x92,0x0d,0x4a,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc9,0x03,0x76,
                            0x6f,0x72,0x62,0x69,0x73,0x1d,0x00,0x00,0x00,0x58,0x69,0x70,0x68,0x2e,0x4f,0x72,0x67,0x20,0x6c,0x69,
                            0x62,0x56,0x6f,0x72,0x62,0x69,0x73,0x20,0x49,0x20,0x32,0x30,0x30,0x39,0x30,0x36,0x32,0x34,0x01,0x00,
                            0x00,0x00,0x19,0x00,0x00,0x00,0x45,0x4e,0x43,0x4f,0x44,0x45,0x52,0x3d,0x65,0x6e,0x63,0x6f,0x64,0x65,
                            0x72,0x5f,0x65,0x78,0x61,0x6d,0x70,0x6c,0x65,0x2e,0x63,0x01,0x05,0x76,0x6f,0x72,0x62,0x69,0x73,0x1f,
                            0x42,0x43,0x56,0x01,0x00,0x00,0x01,0x00,0x18,0x63,0x54,0x29,0x46,0x99,0x52,0xd2,0x4a,0x89,0x19,0x73,
                            0x94,0x31,0x46,0x99,0x62,0x92,0x4a,0x89,0xa5,0x84,0x16,0x42,0x48,0x9d,0x73,0x14,0x53,0xa9,0x39,0xd7,
                            0x9c,0x6b,0xac,0xb9,0xb5,0x20,0x84,0x10,0x1a,0x53,0x50,0x29,0x05,0x99,0x52,0x8e,0x52,0x69,0x19,0x63,
                            0x90,0x29,0x05,0x99,0x52,0x10,0x4b,0x49,0x25,0x74,0x12,0x3a,0x27,0x9d,0x63,0x10,0x5b,0x49,0xc1,0xd6,
                            0x98,0x6b,0x8b,0x41,0xb6,0x1c,0x84,0x0d,0x9a,0x52,0x4c,0x29,0xc4,0x94,0x52,0x8a,0x42,0x08,0x19,0x53,
                            0x8c,0x29,0xc5,0x94,0x52,0x4a,0x42,0x07,0x25,0x74,0x0e,0x3a,0xe6,0x1c,0x53,0x8e,0x4a,0x28,0x41,0xb8,
                            0x9c,0x73,0xab,0xb5,0x96,0x96,0x63,0x8b,0xa9,0x74,0x92,0x4a,0xe7,0x24,0x64,0x4c,0x42,0x48,0x29,0x85,
                            0x92,0x4a,0x07,0xa5,0x53,0x4e,0x42,0x48,0x35,0x96,0xd6,0x52,0x29,0x1d,0x73,0x52,0x52,0x6a,0x41,0xe8,
                            0x20,0x84,0x10,0x42,0xb6,0x20,0x84,0x0d,0x82,0xd0,0x90,0x55,0x00,0x00,0x01,0x00,0xc0,0x40,0x10,0x1a,
                            0xb2,0x0a,0x00,0x50,0x00,0x00,0x10,0x8a,0xa1,0x18,0x8a,0x02,0x84,0x86,0xac,0x02,0x00,0x32,0x00,0x00,
                            0x04,0xa0,0x28,0x8e,0xe2,0x28,0x8e,0x23,0x39,0x92,0x63,0x49,0x16,0x10,0x1a,0xb2,0x0a,0x00,0x00,0x02,
                            0x00,0x10,0x00,0x00,0xc0,0x70,0x14,0x49,0x91,0x14,0xc9,0xb1,0x24,0x4b,0xd2,0x2c,0x4b,0xd3,0x44,0x51,
                            0x55,0x7d,0xd5,0x36,0x55,0x55,0xf6,0x75,0x5d,0xd7,0x75,0x5d,0xd7,0x75,0x20,0x34,0x64,0x15,0x00,0x00,
                            0x01,0x00,0x40,0x48,0xa7,0x99,0xa5,0x1a,0x20,0xc2,0x0c,0x64,0x18,0x08,0x0d,0x59,0x05,0x00,0x20,0x00,
                            0x00,0x00,0x46,0x28,0xc2,0x10,0x03,0x42,0x43,0x56,0x01,0x00,0x00,0x01,0x00,0x00,0x62,0x28,0x39,0x88,
                            0x26,0xb4,0xe6,0x7c,0x73,0x8e,0x83,0x66,0x39,0x68,0x2a,0xc5,0xe6,0x74,0x70,0x22,0xd5,0xe6,0x49,0x6e,
                            0x2a,0xe6,0xe6,0x9c,0x73,0xce,0x39,0x27,0x9b,0x73,0xc6,0x38,0xe7,0x9c,0x73,0x8a,0x72,0x66,0x31,0x68,
                            0x26,0xb4,0xe6,0x9c,0x73,0x12,0x83,0x66,0x29,0x68,0x26,0xb4,0xe6,0x9c,0x73,0x9e,0xc4,0xe6,0x41,0x6b,
                            0xaa,0xb4,0xe6,0x9c,0x73,0xc6,0x39,0xa7,0x83,0x71,0x46,0x18,0xe7,0x9c,0x73,0x9a,0xb4,0xe6,0x41,0x6a,
                            0x36,0xd6,0xe6,0x9c,0x73,0x16,0xb4,0xa6,0x39,0x6a,0x2e,0xc5,0xe6,0x9c,0x73,0x22,0xe5,0xe6,0x49,0x6d,
                            0x2e,0xd5,0xe6,0x9c,0x73,0xce,0x39,0xe7,0x9c,0x73,0xce,0x39,0xe7,0x9c,0x73,0xaa,0x17,0xa7,0x73,0x70,
                            0x4e,0x38,0xe7,0x9c,0x73,0xa2,0xf6,0xe6,0x5a,0x6e,0x42,0x17,0xe7,0x9c,0x73,0x3e,0x19,0xa7,0x7b,0x73,
                            0x42,0x38,0xe7,0x9c,0x73,0xce,0x39,0xe7,0x9c,0x73,0xce,0x39,0xe7,0x9c,0x73,0x82,0xd0,0x90,0x55,0x00,
                            0x00,0x10,0x00,0x00,0x41,0x18,0x36,0x86,0x71,0xa7,0x20,0x48,0x9f,0xa3,0x81,0x18,0x45,0x88,0x69,0xc8,
                            0xa4,0x07,0xdd,0xa3,0xc3,0x24,0x68,0x0c,0x72,0x0a,0xa9,0x47,0xa3,0xa3,0x91,0x52,0xea,0x20,0x94,0x54,
                            0xc6,0x49,0x29,0x9d,0x20,0x34,0x64,0x15,0x00,0x00,0x08,0x00,0x00,0x21,0x84,0x14,0x52,0x48,0x21,0x85,
                            0x14,0x52,0x48,0x21,0x85,0x14,0x52,0x88,0x21,0x86,0x18,0x62,0xc8,0x29,0xa7,0x9c,0x82,0x0a,0x2a,0xa9,
                            0xa4,0xa2,0x8a,0x32,0xca,0x2c,0xb3,0xcc,0x32,0xcb,0x2c,0xb3,0xcc,0x32,0xeb,0xb0,0xb3,0xce,0x3a,0xec,
                            0x30,0xc4,0x10,0x43,0x0c,0xad,0xb4,0x12,0x4b,0x4d,0xb5,0xd5,0x58,0x63,0xad,0xb9,0xe7,0x9c,0x6b,0x0e,
                            0xd2,0x5a,0x69,0xad,0xb5,0xd6,0x4a,0x29,0xa5,0x94,0x52,0x4a,0x29,0x08,0x0d,0x59,0x05,0x00,0x80,0x00,
                            0x00,0x10,0x08,0x19,0x64,0x90,0x41,0x46,0x21,0x85,0x14,0x52,0x88,0x21,0xa6,0x9c,0x72,0xca,0x29,0xa8,
                            0xa0,0x02,0x42,0x43,0x56,0x01,0x00,0x80,0x00,0x00,0x02,0x00,0x00,0x00,0x3c,0xc9,0x73,0x44,0x47,0x74,
                            0x44,0x47,0x74,0x44,0x47,0x74,0x44,0x47,0x74,0x44,0xc7,0x73,0x3c,0x47,0x94,0x44,0x49,0x94,0x44,0x49,
                            0xb4,0x4c,0xcb,0xd4,0x4c,0x4f,0x15,0x55,0xd5,0x95,0x5d,0x5b,0xd6,0x65,0xdd,0xf6,0x6d,0x61,0x17,0x76,
                            0xdd,0xf7,0x75,0xdf,0xf7,0x75,0xe3,0xd7,0x85,0x61,0x59,0x96,0x65,0x59,0x96,0x65,0x59,0x96,0x65,0x59,
                            0x96,0x65,0x59,0x96,0x65,0x59,0x82,0xd0,0x90,0x55,0x00,0x00,0x08,0x00,0x00,0x80,0x10,0x42,0x08,0x21,
                            0x85,0x14,0x52,0x48,0x21,0xa5,0x18,0x63,0xcc,0x31,0xe7,0xa0,0x93,0x50,0x42,0x20,0x34,0x64,0x15,0x00,
                            0x00,0x08,0x00,0x20,0x00,0x00,0x00,0xc0,0x51,0x1c,0xc5,0x71,0x24,0x47,0x72,0x24,0xc9,0x92,0x2c,0x49,
                            0x93,0x34,0x4b,0xb3,0x3c,0xcd,0xd3,0x3c,0x4d,0xf4,0x44,0x51,0x14,0x4d,0xd3,0x54,0x45,0x57,0x74,0x45,
                            0xdd,0xb4,0x45,0xd9,0x94,0x4d,0xd7,0x74,0x4d,0xd9,0x74,0x55,0x59,0xb5,0x5d,0x59,0xb6,0x6d,0xd9,0xd6,
                            0x6d,0x5f,0x96,0x6d,0xdf,0xf7,0x7d,0xdf,0xf7,0x7d,0xdf,0xf7,0x7d,0xdf,0xf7,0x7d,0xdf,0xf7,0x75,0x1d,
                            0x08,0x0d,0x59,0x05,0x00,0x48,0x00,0x00,0xe8,0x48,0x8e,0xa4,0x48,0x8a,0xa4,0x48,0x8e,0xe3,0x38,0x92,
                            0x24,0x01,0xa1,0x21,0xab,0x00,0x00,0x19,0x00,0x00,0x01,0x00,0x28,0x8a,0xa3,0x38,0x8e,0xe3,0x48,0x92,
                            0x24,0x49,0x96,0xa4,0x49,0x9e,0xe5,0x59,0xa2,0x66,0x6a,0xa6,0x67,0x7a,0xaa,0xa8,0x02,0xa1,0x21,0xab,
                            0x00,0x00,0x40,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x28,0x9a,0xe2,0x29,0xa6,0xe2,0x29,0xa2,0xe2,
                            0x39,0xa2,0x23,0x4a,0xa2,0x65,0x5a,0xa2,0xa6,0x6a,0xae,0x28,0x9b,0xb2,0xeb,0xba,0xae,0xeb,0xba,0xae,
                            0xeb,0xba,0xae,0xeb,0xba,0xae,0xeb,0xba,0xae,0xeb,0xba,0xae,0xeb,0xba,0xae,0xeb,0xba,0xae,0xeb,0xba,
                            0xae,0xeb,0xba,0xae,0xeb,0xba,0xae,0xeb,0xba,0x2e,0x10,0x1a,0xb2,0x0a,0x00,0x90,0x00,0x00,0xd0,0x91,
                            0x1c,0xc9,0x91,0x1c,0x49,0x91,0x14,0x49,0x91,0x1c,0xc9,0x01,0x42,0x43,0x56,0x01,0x00,0x32,0x00,0x00,
                            0x02,0x00,0x70,0x0c,0xc7,0x90,0x14,0xc9,0xb1,0x2c,0x4b,0xd3,0x3c,0xcd,0xd3,0x3c,0x4d,0xf4,0x44,0x4f,
                            0xf4,0x4c,0x4f,0x15,0x5d,0xd1,0x05,0x42,0x43,0x56,0x01,0x00,0x80,0x00,0x00,0x02,0x00,0x00,0x00,0x00,
                            0x00,0x30,0x24,0xc3,0x52,0x2c,0x47,0x73,0x34,0x49,0x94,0x54,0x4b,0xb5,0x54,0x4d,0xb5,0x54,0x4b,0x15,
                            0x55,0x4f,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,
                            0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x35,0x4d,0xd3,0x34,0x4d,
                            0x20,0x34,0x64,0x25,0x00,0x00,0x04,0x00,0xc0,0x62,0x8d,0xc1,0xe5,0x20,0x21,0x25,0x25,0xe5,0xde,0x10,
                            0xc2,0x10,0x93,0x9e,0x31,0x26,0x21,0xb5,0x5e,0x21,0x04,0x91,0x92,0xde,0x31,0x06,0x15,0x83,0x9e,0x32,
                            0xa2,0x0c,0x72,0xde,0x42,0xe3,0x10,0x83,0x1e,0x08,0x0d,0x59,0x11,0x00,0x44,0x01,0x00,0x00,0xc6,0x20,
                            0xc7,0x10,0x73,0xc8,0x39,0x47,0xa9,0x93,0x12,0x39,0xe7,0xa8,0x74,0x94,0x1a,0xe7,0x1c,0xa5,0x8e,0x52,
                            0x67,0x29,0xc5,0x98,0x62,0xcd,0x28,0x95,0xd8,0x52,0xac,0x8d,0x73,0x8e,0x52,0x47,0xad,0xa3,0x94,0x62,
                            0x2c,0x2d,0x76,0x94,0x52,0x8d,0xa9,0xc6,0x02,0x00,0x00,0x02,0x1c,0x00,0x00,0x02,0x2c,0x84,0x42,0x43,
                            0x56,0x04,0x00,0x51,0x00,0x00,0x84,0x31,0x48,0x29,0xa4,0x14,0x62,0x8c,0x39,0xa7,0x9c,0x43,0x8c,0x29,
                            0xe7,0x98,0x73,0x86,0x31,0xe6,0x1c,0x73,0x8e,0x39,0xe7,0xa0,0x74,0x52,0x2a,0xe7,0x9c,0x74,0x4e,0x4a,
                            0xc4,0x18,0x73,0x8e,0x39,0xa7,0x9c,0x73,0x52,0x3a,0x27,0x95,0x73,0x4e,0x4a,0x27,0xa1,0x00,0x00,0x80,
                            0x00,0x07,0x00,0x80,0x00,0x0b,0xa1,0xd0,0x90,0x15,0x01,0x40,0x9c,0x00,0x80,0x41,0x92,0x3c,0x4f,0xf2,
                            0x34,0x51,0x94,0x34,0x4f,0x14,0x45,0x53,0x74,0x5d,0x51,0x34,0x5d,0xd7,0xf2,0x3c,0xd5,0xf4,0x4c,0x53,
                            0x55,0x3d,0xd1,0x54,0x55,0x53,0x55,0x6d,0xd9,0x54,0x55,0x59,0x96,0x3c,0xcf,0x34,0x3d,0xd3,0x54,0x55,
                            0xcf,0x34,0x55,0xd5,0x54,0x55,0x59,0x36,0x55,0x55,0x96,0x45,0x55,0xd5,0x6d,0xd3,0x75,0x75,0xdb,0x74,
                            0x55,0xdd,0x96,0x6d,0xdb,0xf7,0x5d,0x5b,0x16,0x76,0x51,0x55,0x6d,0xdd,0x54,0x5d,0xdb,0x37,0x55,0xd7,
                            0xf6,0x5d,0xd9,0xf6,0x7d,0x59,0xd6,0x75,0x63,0xf2,0x3c,0x55,0xf5,0x4c,0xd3,0x75,0x3d,0xd3,0x74,0x65,
                            0xd5,0x75,0x6d,0x5b,0x75,0x5d,0x5d,0xf7,0x4c,0x53,0x96,0x4d,0xd7,0x95,0x65,0xd3,0x75,0x6d,0xdb,0x95,
                            0x65,0x5d,0x77,0x65,0xd9,0xf7,0x35,0xd3,0x74,0x5d,0xd3,0x55,0x65,0xd9,0x74,0x5d,0xd9,0x76,0x65,0x57,
                            0xb7,0x5d,0x59,0xf6,0x7d,0xd3,0x75,0x85,0xdf,0x95,0x65,0x5f,0x57,0x65,0x59,0x18,0x76,0x5d,0xf7,0x85,
                            0x5b,0xd7,0x95,0xe5,0x74,0x5d,0xdd,0x57,0x65,0x57,0x37,0x56,0x59,0xf6,0x7d,0x5b,0xd7,0x85,0xe1,0xd6,
                            0x75,0x61,0x99,0x3c,0x4f,0x55,0x3d,0xd3,0x74,0x5d,0xcf,0x34,0x5d,0x57,0x75,0x5d,0x5f,0x57,0x5d,0xd7,
                            0xd6,0x35,0xd3,0x94,0x65,0xd3,0x75,0x6d,0xd9,0x54,0x5d,0x59,0x76,0x65,0xd9,0xf7,0x5d,0x57,0xd6,0x75,
                            0xcf,0x34,0x65,0xd9,0x74,0x5d,0xdb,0x36,0x5d,0x57,0x96,0x5d,0x59,0xf6,0x7d,0x57,0x96,0x75,0xdd,0x74,
                            0x5d,0x5f,0x57,0x65,0x59,0xf8,0x55,0x57,0xf6,0x75,0x59,0xd7,0x95,0xe1,0xd6,0x6d,0xe1,0x37,0x5d,0xd7,
                            0xf7,0x55,0x59,0xf6,0x85,0x57,0x96,0x75,0xe1,0xd6,0x75,0x61,0xb9,0x75,0x5d,0x18,0x3e,0x55,0xf5,0x7d,
                            0x53,0x76,0x85,0xe1,0x74,0x65,0xdf,0xd7,0x85,0xdf,0x59,0x6e,0x5d,0x38,0x96,0xd1,0x75,0x7d,0x61,0x95,
                            0x6d,0xe1,0x58,0x65,0x59,0x39,0x7e,0xe1,0x58,0x96,0xdd,0xf7,0x95,0x65,0x74,0x5d,0x5f,0x58,0x6d,0xd9,
                            0x18,0x56,0x59,0x16,0x86,0x5f,0xf8,0x9d,0xe5,0xf6,0x7d,0xe3,0x78,0x75,0x5d,0x19,0x6e,0xdd,0xe7,0xcc,
                            0xba,0xef,0x0c,0xc7,0xef,0xa4,0xfb,0xca,0xd3,0xd5,0x6d,0x63,0x99,0x7d,0xdd,0x59,0x66,0x5f,0x77,0x8e,
                            0xe1,0x18,0x3a,0xbf,0xf0,0xe3,0xa9,0xaa,0xaf,0x9b,0xae,0x2b,0x0c,0xa7,0x2c,0x0b,0xbf,0xed,0xeb,0xc6,
                            0xb3,0xfb,0xbe,0xb2,0x8c,0xae,0xeb,0xfb,0xaa,0x2c,0x0b,0xbf,0x2a,0xdb,0xc2,0xb1,0xeb,0xbe,0xf3,0xfc,
                            0xbe,0xb0,0x2c,0xa3,0xec,0xfa,0xc2,0x6a,0xcb,0xc2,0xb0,0xda,0xb6,0x31,0xdc,0xbe,0x6e,0x2c,0xbf,0x70,
                            0x1c,0xcb,0x6b,0xeb,0xca,0x31,0xeb,0xbe,0x51,0xb6,0x75,0x7c,0x5f,0x78,0x0a,0xc3,0xf3,0x74,0x75,0x5d,
                            0x79,0x66,0x5d,0xc7,0xf6,0x75,0x74,0xe3,0x47,0x38,0x7e,0xca,0x00,0x00,0x80,0x01,0x07,0x00,0x80,0x00,
                            0x13,0xca,0x40,0xa1,0x21,0x2b,0x02,0x80,0x38,0x01,0x00,0x8f,0x24,0x89,0xa2,0x64,0x59,0xa2,0x28,0x59,
                            0x96,0x28,0x8a,0xa6,0xe8,0xba,0xa2,0x68,0xba,0xae,0xa4,0x69,0xa6,0xa9,0x69,0x9e,0x69,0x5a,0x9a,0x67,
                            0x9a,0xa6,0x69,0xaa,0xb2,0x29,0x9a,0xae,0x2c,0x69,0x9a,0x69,0x5a,0x9e,0x66,0x9a,0x9a,0xa7,0x99,0xa6,
                            0x68,0x9a,0xae,0x6b,0x9a,0xa6,0xac,0x8a,0xa6,0x29,0xcb,0xa6,0x6a,0xca,0xb2,0x69,0x9a,0xb2,0xec,0xba,
                            0xb2,0x6d,0xbb,0xae,0x6c,0xdb,0xa2,0x69,0xca,0xb2,0x69,0x9a,0xb2,0x6c,0x9a,0xa6,0x2c,0xbb,0xb2,0xab,
                            0xdb,0xae,0xec,0xea,0xba,0xa4,0x59,0xa6,0xa9,0x79,0x9e,0x69,0x6a,0x9e,0x67,0x9a,0xa6,0x6a,0xca,0xb2,
                            0x69,0x9a,0xae,0xab,0x79,0x9e,0x6a,0x7a,0x9e,0x68,0xaa,0x9e,0x28,0xaa,0xaa,0x6a,0xaa,0xaa,0xad,0xaa,
                            0xaa,0x2c,0x5b,0x9e,0x67,0x9a,0x9a,0xe8,0xa9,0xa6,0x27,0x8a,0xaa,0x6a,0xaa,0xa6,0xad,0x9a,0xaa,0x2a,
                            0xcb,0xa6,0xaa,0xda,0xb2,0x69,0xaa,0xb6,0x6c,0xaa,0xaa,0x6d,0xbb,0xaa,0xec,0xfa,0xb2,0x6d,0xeb,0xba,
                            0x69,0xaa,0xb2,0x6d,0xaa,0xa6,0x2d,0x9b,0xaa,0x6a,0xdb,0xae,0xec,0xea,0xb2,0x2c,0xdb,0xba,0x2f,0x69,
                            0x9a,0x69,0x6a,0x9e,0x67,0x9a,0x9a,0xe7,0x99,0xa6,0x69,0x9a,0xb2,0x6c,0x9a,0xaa,0x2b,0x5b,0x9e,0xa7,
                            0x9a,0x9e,0x28,0xaa,0xaa,0xe6,0x89,0xa6,0x6a,0xaa,0xaa,0x2c,0x9b,0xa6,0xaa,0xca,0x96,0xe7,0x99,0xaa,
                            0x27,0x8a,0xaa,0xea,0x89,0x9e,0x6b,0x9a,0xaa,0x2a,0xcb,0xa6,0x6a,0xda,0xaa,0x69,0x9a,0xb6,0x6c,0xaa,
                            0xaa,0x2d,0x9b,0xa6,0x2a,0xcb,0xae,0x6d,0xfb,0xbe,0xeb,0xca,0xb2,0x6e,0xaa,0xaa,0x6c,0x9b,0xaa,0x6a,
                            0xeb,0xa6,0x6a,0xca,0xb2,0x6c,0xcb,0xbe,0xef,0xca,0xaa,0xee,0x8a,0xa6,0x29,0xcb,0xa6,0xaa,0xda,0xb2,
                            0x69,0xaa,0xb2,0x2d,0xdb,0xb2,0xef,0xcb,0xb2,0xac,0xfb,0xa2,0x69,0xca,0xb2,0x69,0xaa,0xb2,0x6d,0xaa,
                            0xaa,0x2e,0xcb,0xb2,0x6d,0x1b,0xb3,0x6c,0xfb,0xba,0x68,0x9a,0xb2,0x6d,0xaa,0xa6,0x2d,0x9b,0xaa,0x2a,
                            0xdb,0xb2,0x2d,0xfb,0xba,0x2c,0xdb,0xba,0xef,0xca,0xae,0x6f,0xab,0xaa,0xac,0xeb,0xb2,0x2d,0xfb,0xba,
                            0xee,0xfa,0xae,0x70,0xeb,0xba,0x30,0xbc,0xb2,0x6c,0xfb,0xaa,0xac,0xfa,0xba,0x2b,0xdb,0xba,0x6f,0xeb,
                            0x32,0xdb,0xf6,0x7d,0x44,0xd3,0x94,0x65,0x53,0x35,0x6d,0xdb,0x54,0x55,0x59,0x76,0x65,0xd9,0xf6,0x65,
                            0xdb,0xf6,0x7d,0xd1,0x34,0x6d,0x5b,0x55,0x55,0x5b,0x36,0x4d,0xd5,0xb6,0x65,0x59,0xf6,0x7d,0x59,0xb6,
                            0x6d,0x61,0x34,0x4d,0xd9,0x36,0x55,0x55,0xd6,0x4d,0xd5,0xb4,0x6d,0x59,0x96,0x6d,0x61,0xb6,0x65,0xe1,
                            0x76,0x65,0xd9,0xb7,0x65,0x5b,0xf6,0x75,0xd7,0x95,0x75,0x5f,0xd7,0x7d,0xe3,0xd7,0x65,0xdd,0xe6,0xba,
                            0xb2,0xed,0xcb,0xb2,0xad,0xfb,0xaa,0xab,0xfa,0xb6,0xee,0xfb,0xc2,0x70,0xeb,0xae,0xf0,0x0a,0x00,0x00,
                            0x18,0x70,0x00,0x00,0x08,0x31,0xa1,0x0c,0x14,0x1a,0xb2,0x12,0x00,0x88,0x02,0x00,0x00,0x8c,0x61,0x8c,
                            0x31,0x08,0x8d,0x52,0xce,0x39,0x07,0xa1,0x51,0xca,0x39,0xe7,0x20,0x64,0xce,0x41,0x08,0x21,0x95,0xcc,
                            0x39,0x08,0x21,0x94,0x92,0x39,0x07,0xa1,0x94,0x94,0x32,0xe7,0x20,0x94,0x92,0x52,0x08,0xa1,0x94,0x94,
                            0x5a,0x0b,0x21,0x94,0x94,0x52,0x6b,0x05,0x00,0x00,0x14,0x38,0x00,0x00,0x04,0xd8,0xa0,0x29,0xb1,0x38,
                            0x40,0xa1,0x21,0x2b,0x01,0x80,0x54,0x00,0x00,0x83,0xe3,0x58,0x96,0xe7,0x99,0xa2,0x6a,0xda,0xb2,0x63,
                            0x49,0x9e,0x27,0x8a,0xaa,0xa9,0xaa,0xb6,0xed,0x48,0x96,0xe7,0x89,0xa2,0x69,0xaa,0xaa,0x6d,0x5b,0x9e,
                            0x27,0x8a,0xa6,0xa9,0xaa,0xae,0xeb,0xeb,0x9a,0xe7,0x89,0xa2,0x69,0xaa,0xaa,0xeb,0xea,0xba,0x68,0x9a,
                            0xa6,0xa9,0xaa,0xae,0xeb,0xba,0xba,0x2e,0x9a,0xa2,0xa9,0xaa,0xaa,0xeb,0xba,0xb2,0xae,0x9b,0xa6,0xaa,
                            0xaa,0xae,0x2b,0xbb,0xb2,0xec,0xeb,0xa6,0xaa,0xaa,0xaa,0xeb,0xca,0xae,0x2c,0xfb,0xc2,0xaa,0xba,0xae,
                            0x2b,0xcb,0xb2,0x6d,0xeb,0xc2,0xb0,0xaa,0xae,0xeb,0xca,0xb2,0x6c,0xdb,0xb6,0x6f,0xdc,0xba,0xae,0xeb,
                            0xbe,0xef,0xfb,0xc2,0x91,0xad,0xeb,0xba,0x2e,0xfc,0xc2,0x31,0x0c,0x47,0x01,0x00,0xe0,0x09,0x0e,0x00,
                            0x40,0x05,0x36,0xac,0x8e,0x70,0x52,0x34,0x16,0x58,0x68,0xc8,0x4a,0x00,0x20,0x03,0x00,0x80,0x30,0x06,
                            0x21,0x83,0x10,0x42,0x06,0x21,0x84,0x90,0x52,0x4a,0x21,0xa5,0x94,0x12,0x00,0x00,0x30,0xe0,0x00,0x00,
                            0x10,0x60,0x42,0x19,0x28,0x34,0x64,0x25,0x00,0x10,0x03,0x00,0x00,0x10,0x01,0x21,0x83,0x10,0x42,0x08,
                            0x21,0x84,0x10,0x42,0x08,0x21,0x84,0x10,0x42,0x08,0x21,0x84,0x10,0x42,0xe7,0x9c,0x73,0xce,0x39,0xe7,
                            0x9c,0x73,0xce,0x09,0x00,0xd8,0x8f,0x70,0x00,0x90,0x7a,0x30,0x31,0x31,0x85,0x85,0x86,0xac,0x04,0x00,
                            0x52,0x01,0x00,0x00,0x63,0x94,0x52,0x8a,0x31,0xe7,0x20,0x44,0x8c,0x39,0xc6,0x18,0x74,0x12,0x4a,0x8a,
                            0x18,0x73,0x8e,0x31,0x07,0xa5,0xa4,0x54,0x39,0x07,0x21,0x84,0x54,0x5a,0xcb,0xad,0x72,0x0e,0x42,0x08,
                            0x29,0xb5,0x54,0x5b,0xe6,0x9c,0x94,0xd6,0x62,0x8c,0x39,0xc6,0xcc,0x39,0x29,0x29,0xc5,0x56,0x73,0xce,
                            0xa1,0x94,0xd4,0x62,0xac,0xb9,0xe6,0x9a,0x3b,0x29,0xad,0xd5,0x9a,0x6b,0xcd,0xb9,0x96,0xd6,0x6a,0xcd,
                            0x35,0xe7,0x5c,0x73,0x2e,0xad,0xc5,0x9a,0x6b,0xce,0x35,0xe7,0xdc,0x72,0xcc,0x35,0xe7,0x9c,0x73,0xce,
                            0x39,0xc6,0x9c,0x73,0xce,0x39,0xe7,0x9c,0x73,0x01,0x00,0x38,0x0d,0x0e,0x00,0xa0,0x07,0x36,0xac,0x8e,
                            0x70,0x52,0x34,0x16,0x58,0x68,0xc8,0x4a,0x00,0x20,0x15,0x00,0x80,0x40,0x46,0x29,0xc6,0x9c,0x73,0x16,
                            0x3a,0x84,0x14,0x63,0xce,0x39,0x07,0x21,0x84,0x48,0x21,0xc6,0x9c,0x73,0x0e,0x42,0x08,0x15,0x63,0xce,
                            0x39,0x07,0x1d,0x84,0x10,0x2a,0xc6,0x1c,0x73,0x0e,0x42,0x08,0x21,0x64,0xce,0x39,0x07,0x21,0x84,0x10,
                            0x42,0xc8,0x9c,0x83,0x0e,0x3a,0x08,0x21,0x84,0xd0,0x41,0x07,0x21,0x84,0x10,0x42,0x28,0xa5,0x73,0x10,
                            0x42,0x08,0x21,0x84,0x12,0x4a,0x08,0x21,0x84,0x10,0x42,0x08,0x21,0x84,0x0e,0x42,0x08,0x21,0x84,0x10,
                            0x42,0x08,0x21,0x84,0x10,0x42,0x08,0xa1,0x94,0x12,0x42,0x08,0x21,0x84,0x50,0x42,0x28,0x25,0x14,0x00,
                            0x00,0x58,0xe0,0x00,0x00,0x10,0x60,0xc3,0xea,0x08,0x27,0x45,0x63,0x81,0x85,0x86,0xac,0x04,0x00,0x80,
                            0x00,0x00,0x20,0x87,0x25,0xa8,0x94,0x33,0x61,0x90,0x63,0xd0,0x63,0x43,0x90,0x72,0xd4,0x4c,0x83,0x10,
                            0x53,0x4e,0x74,0xa6,0x98,0x93,0xda,0x4c,0xc5,0x14,0x64,0x0e,0x44,0x27,0x9d,0x44,0x86,0x5a,0x50,0xb6,
                            0x97,0xcc,0x02,0x00,0x00,0x20,0x08,0x00,0x08,0x30,0x01,0x04,0x06,0x08,0x0a,0xbe,0x10,0x02,0x62,0x0c,
                            0x00,0x40,0x10,0x22,0x33,0x44,0x42,0x61,0x15,0x2c,0x30,0x28,0x83,0x06,0x87,0x79,0x00,0xf0,0x00,0x11,
                            0x21,0x11,0x00,0x24,0x26,0x28,0xd2,0x2e,0x2e,0xa0,0xcb,0x00,0x17,0x74,0x71,0xd7,0x81,0x10,0x82,0x10,
                            0x84,0x20,0x16,0x07,0x50,0x40,0x02,0x0e,0x4e,0xb8,0xe1,0x89,0x37,0x3c,0xe1,0x06,0x27,0xe8,0x14,0x95,
                            0x3a,0x08,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x78,0x00,0x00,0x38,0x28,0x80,0x88,0x88,0xe6,0x2a,0x2c,
                            0x2e,0x30,0x32,0x34,0x36,0x38,0x3a,0x3c,0x02,0x00,0x00,0x00,0x00,0x40,0x05,0x00,0x3e,0x00,0x00,0x8e,
                            0x0f,0x20,0x22,0xa2,0xb9,0x0a,0x8b,0x0b,0x8c,0x0c,0x8d,0x0d,0x8e,0x0e,0x8f,0x00,0x00,0x00,0x00,0x00,
                            0x00,0x00,0x00,0x00,0x20,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x20,0x20,0x4f,0x67,
                            0x67,0x53,0x00,0x04,0x45,0x2d,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0xa9,0x6e,0x22,0x52,0x02,0x00,0x00,
                            0x00,0x28,0x9f,0xc6,0x86,0x17,0x49,0x44,0xa0,0x48,0x48,0x48,0x48,0x48,0x48,0x48,0x48,0x48,0x48,0x48,
                            0x91,0x28,0x28,0x28,0x28,0x28,0x28,0x3f,0x44,0xa4,0x69,0x10,0x81,0xf4,0xcc,0x13,0x00,0xdd,0x3f,0xd6,
                            0xdb,0xf0,0x63,0xbd,0x0d,0x31,0xda,0x87,0xd9,0xef,0xb3,0xb7,0x7c,0x98,0x78,0x9f,0xfd,0xc9,0x01,0xfb,
                            0x26,0xef,0xfe,0xc7,0x01,0xfb,0x26,0x9f,0x3a,0xf5,0xb9,0x1b,0x94,0xf3,0xe7,0xdc,0xa0,0x28,0x35,0xcf,
                            0xf8,0x68,0x63,0x9e,0xd1,0xc6,0x7c,0xf3,0xcd,0x37,0x5f,0x7a,0x7f,0x20,0x77,0xb5,0x78,0x57,0x72,0x74,
                            0xbe,0xaa,0xbd,0x1b,0xed,0x4c,0x4e,0x2f,0x7d,0x09,0x1c,0xbe,0xbd,0x73,0x83,0xb8,0x39,0x5f,0xfd,0x3e,
                            0xc6,0xe3,0xac,0x4a,0x6e,0x0e,0x57,0x96,0xdf,0xb9,0x7e,0xd6,0x41,0xe5,0xdf,0x66,0x5e,0x50,0xda,0x4f,
                            0x5f,0xf3,0x03,0xd9,0xaf,0xca,0x0b,0xea,0xa2,0x5c,0x5c,0x96,0x8e,0xbd,0x57,0xbf,0xde,0xf3,0xbb,0xb9,
                            0x54,0xde,0xde,0xb9,0xcb,0x4a,0xf7,0x92,0x10,0x55,0xe9,0x86,0x9f,0x2b,0xb7,0xde,0x1a,0x9d,0xe5,0xea,
                            0x97,0x47,0x36,0x87,0x85,0xef,0x72,0x5b,0xcd,0xeb,0x2d,0xe4,0x6e,0x4c,0x4e,0xde,0x78,0xb6,0xfa,0xe9,
                            0x43,0x1f,0xcf,0x10,0xab,0xb7,0xfe,0xfe,0xc7,0x9d,0x1e,0xf1,0xa2,0x4f,0xdf,0x24,0xf9,0x77,0xb2,0x41,
                            0xfc,0x3a,0xff,0x3d,0x9c,0x77,0x0b,0x0e,0xbd,0xf8,0x64,0xd9,0xfa,0x9b,0x0d,0x6d,0x3f,0x5f,0xbb,0x91,
                            0x43,0xd0,0x49,0x15,0x5e,0xbc,0x7a,0xe6,0x54,0x53,0x56,0x9c,0x84,0x81,0xdd,0x31,0x3a,0xbe,0x73,0x5b,
                            0xfd,0x92,0x22,0x65,0x00,0x1c,0x26,0xd2,0x5f,0x13,0x58,0x08,0xc8,0xde,0xa3,0x2b,0xef,0xfc,0x39,0xa6,
                            0xba,0x68,0x6e,0xbe,0x28,0x74,0x19,0x9e,0x74,0x02,0x64,0x01,0xfe,0x1a,0x00,0x49,0x3b,0xa8,0xca,0x47,
                            0x63,0xa5,0x4b,0xd8,0x0b,0x52,0xf1,0x03,0x00,0x64,0x80,0x01,0x50,0x31,0x03,0x00,0x7c,0xc3,0x76,0x46,
                            0x82,0xc9,0x39,0x99,0xbe,0x72,0x35,0xdb,0x3a,0x9a,0x37,0xf0,0x4c,0x52,0x1a,0x4f,0xe1,0xd9,0x57,0xe6,
                            0x64,0x4e,0x4b,0x6e,0x8f,0xe6,0x45,0x7d,0xfd,0xfc,0xda,0x62,0xa2,0x37,0x7e,0x2e,0xf1,0x9f,0xcf,0x5f,
                            0x0e,0x7e,0x6f,0xfd,0x1c,0xdf,0x6a,0xcb,0xde,0xaf,0x5e,0x7d,0xb6,0x79,0x3c,0xf4,0xde,0xcd,0xad,0x57,
                            0xbc,0x3f,0x1f,0x7a,0x6a,0x36,0x9d,0xd7,0xcd,0x6f,0xcf,0xbe,0xbb,0x62,0x6e,0x77,0x50,0xbf,0xdb,0xf4,
                            0x94,0x3b,0x92,0xbf,0xae,0x2d,0x81,0x2f,0x7f,0xfe,0xed,0x5e,0x7b,0xf8,0xf4,0x02,0xb5,0xc0,0xb5,0xb0,
                            0xb5,0x40,0x2d,0x50,0x0b,0x74,0x78,0x83,0x6b,0xe9,0xf0,0x06,0xd7,0xf2,0xcf,0xfe,0xb9,0x7f,0x6e,0xed,
                            0xed,0xed,0xed,0xed,0xed,0xed,0xed,0xed,0xed,0xed,0xed,0xed,0xed,0xed,0xed,0xed,0xed,0xed,0xed,0xed,
                            0xed,0xed,0xed,0xed,0xed,0xed,0xed,0xd7,0xff,0xec,0x9f,0xfb,0xe7,0x76,0xfd,0xe6,0xb1,0xfe,0xe6,0xb1,
                            0xbe,0xbe,0x6e,0xb3,0xbe,0x6e,0x03};
    size_t size = sizeof(data);

    int chan, samplerate;
    short *output;
    int samples = stb_vorbis_decode_memory(data, size, &chan, &samplerate, &output);
    if (samples >= 0)
        free(output);
    return 0;
}
