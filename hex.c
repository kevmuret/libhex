
#include <stdlib.h>
#include <stdio.h>
#include <libhex.h>

int main (const int argc, const char *argv[]) {

	if (argc == 1) {
		exit(EXIT_FAILURE);
		return -1;
	}

	int i;
	for (i = 1; i < argc; i++) {
		char *hex = dechex(atoi(argv[i]));
		printf("%s\r\n", hex);
	}

	exit(EXIT_SUCCESS);
	return 0;
}

