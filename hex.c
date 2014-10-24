
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
	char *hex = calloc(9, sizeof(char));
	for (i = 1; i < argc; i++) {
		dechex(atoi(argv[i]), hex);
		printf("%s\r\n", hex);
	}
	free(hex);

	exit(EXIT_SUCCESS);
	return 0;
}

