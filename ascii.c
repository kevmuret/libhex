
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libhex.h>

int main (const int argc, const char *argv[]) {
	if (argc == 0) {
		exit(EXIT_FAILURE);
		return -1;
	}

	int i;

	init_hexdec();

	if (strcmp(argv[1], "--table") == 0) {
		char *hex = calloc(9, sizeof(char));
		for (i = 0; i < 127; i++) {
			dechex(i, hex);
			printf("%d <=> %s <=> %c\r\n", i, hex, hexascii(hex));
		}
		free(hex);
		
		exit(EXIT_SUCCESS);
		return 0;
	}

	for (i = 1; i < argc; i++) {
		if (strlen(argv[i]) > 1) {
			printf("%c", hexascii(argv[i]));
		}
	}
	printf("\r\n");

	exit(EXIT_SUCCESS);
	return 0;
};

