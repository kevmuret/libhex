
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <libhex.h>

int main (const int argc, const char *argv[]) {

	if (argc == 1) {
		exit(EXIT_FAILURE);
		return -1;
	}

	int i;
	time_t now, now2;
	char *hex = calloc(9, sizeof(char)), *conv = NULL;
	for (i = 1; i < argc; i++) {
		time(&now);
		conv = dechex(atoi(argv[i]), hex, 8, 0);
		time(&now2);
		printf("%f\t%s\r\n", difftime(now2, now), conv);
	}
	free(hex);

	exit(EXIT_SUCCESS);
	return 0;
}

