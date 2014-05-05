
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libhex.h>

int main (const int argc, const char *argv[]) {

	if (argc == 1) {
		exit(EXIT_FAILURE);
		return -1;
	}

	init_hexdec();

	int i;
	for (i = 1; i < argc; i++) {
		printf("%d\r\n", hexdec(argv[i], strlen(argv[i])));
	}

	exit(EXIT_SUCCESS);
	return 0;
}

