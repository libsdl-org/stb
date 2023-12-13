/*
https://github.com/nothings/stb/pull/1490
stb_vorbis: Fix broken clamp in codebook_decode_deinterleave_repeat.
*/

#if 0
g++ -O3 -fsanitize=address,undefined -g -Wall -Wextra vorbis.cpp -ovorbis
exit 0
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <vector>

#include "../../stb_vorbis.c"

int main(int argc, char *argv[])
{
	for(int i = 1; i < argc; i++)
	{
		if(argv[i])
		{
			int16_t *pcm = nullptr;
			int chn, rate;
			FILE *fp = fopen(argv[i], "rb");
			struct stat st;

			if(!fp)
				continue;

			if(fstat(fileno(fp), &st) || st.st_size <= 0)
			{
				fclose(fp);
				continue;
			}
			size_t len = st.st_size;

			std::vector<uint8_t> data(len);
			size_t res = fread(data.data(), len, 1, fp);
			fclose(fp);
			if(!res)
				continue;

			printf("%s: ", argv[i]);
			int ret = stb_vorbis_decode_memory(data.data(), len, &chn, &rate, &pcm);
			printf("%d\n", ret);

			free(pcm);
		}
	}
	return 0;
}
