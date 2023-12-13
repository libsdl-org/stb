/*
https://github.com/nothings/stb/issues/1248
stb_vorbis: out-of-memory when allocating f->temp_mults (libFuzzer/ASan).
*/

#if 0
clang -O3 -fsanitize=address -fno-omit-frame-pointer -g -Wall -Wextra vorbisA.cpp -ovorbisA
exit
#endif

#include <stdint.h>
#include <stdio.h>
#include "stb_vorbis.c"

int main(int argc, char *argv[])
{
  for(int i = 1; i < argc; i++)
  {
    if(argv[i])
    {
      int16_t *pcm =  NULL;
      int chn, rate, ret;

      fprintf(stderr, "%s: ", argv[i]); fflush(stderr);
      ret = stb_vorbis_decode_filename(argv[i], &chn, &rate, &pcm);
      fprintf(stderr, "%d\n", ret);

      free(pcm);
    }
  }
  return 0;
}
