
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int mhexdec[256];
char mdechex[17] = "0123456789ABCDEF";

void init_hexdec () {
	int i = 0, n = 0;
	for (i; i < 256; ++i) {
		if ((i > 47 && i < 58) || (i > 64 && i < 71) || (i > 96 && i < 103)) {
			mhexdec[i] = n++;
		} else {
			mhexdec[i] = -1;
			if (i == 71) {
				n = 10;
			}
		}
	}
};

char* dechex (unsigned dec, char *hex, int len, int fill) {
	if (hex == NULL) {
		len = dec & 0xFFFF0000 ? (dec & 0xFF000000 ? (dec & 0xF0000000 ? 8 : 7) : (dec & 0x00F00000 ? 6 : 5)) : (dec & 0x0000FF00 ? (dec & 0x0000F000 ? 4 : 3) : (dec & 0x000000FF ? (dec & 0x000000F0 ? 2 : 1) : 1));
		hex = malloc((len+1)*sizeof(char));
	}
	char *hex2 = hex+len, *end = hex2;
	*hex2 = '\0';
	for (--hex2; ; hex2--) {
		*hex2 = mdechex[dec & 0xF];
		dec >>= 4;
		if (dec == 0) {
			break;
		}
	}
	// Make the string start at correct address.
	if (fill) {
		if (hex2 > hex) {
			char *c = hex, *s = hex2;
			for (c, s; s < end; s++) {
				*(c++) = *s;
			}
			// Fill with zeros at end
			for (c; c < end; c++) {
				*(c++) = '\0';
			}
		}
		return hex;
	}
	return hex2;
};

/** Keeped for utility purpose : Pointer suppressed to limit memory fetches */
int ishexchar (const int c) {
	return ( (c > 47 && c < 58) || (c > 64 && c < 71) || (c > 96 && c < 103) ) ? 1 : 0;
};

unsigned hexdec (const unsigned char *hex, const int s_hex) {
	if (s_hex == 0) {
		return 0;
	}
	unsigned d = 0, dv = 0, i;
	for (i = 0; i < s_hex; i++) {
		dv = mhexdec[(int) hex[i]];
		if (dv < 0) {
			errno = EINVAL;
			return 0;
		}
		d += dv * (1 << ((s_hex-i-1) << 2));
	}
	return d;
};

char hexascii (const unsigned char *hex) {
	int i1 = mhexdec[(int) hex[0]], i2 = mhexdec[(int) hex[1]];
	if (i1 > -1 && i2 > -1) {
		return (char) ( i1*16 + i2 );
	} else {
		errno = EINVAL;
		return '\0';
	}
};

