
#include <stdlib.h>
#include <math.h>
#include <errno.h>

int mhexdec[103];
char mdechex[17] = "0123456789ABCDEF";

void init_hexdec () {
	mhexdec[48] = 0;
	mhexdec[49] = 1;
	mhexdec[50] = 2;
	mhexdec[51] = 3;
	mhexdec[52] = 4;
	mhexdec[53] = 5;
	mhexdec[54] = 6;
	mhexdec[55] = 7;
	mhexdec[56] = 8;
	mhexdec[57] = 9;
	mhexdec[65] = 10;
	mhexdec[66] = 11;
	mhexdec[67] = 12;
	mhexdec[68] = 13;
	mhexdec[69] = 14;
	mhexdec[70] = 15;
	mhexdec[97] = 10;
	mhexdec[98] = 11;
	mhexdec[99] = 12;
	mhexdec[100] = 13;
	mhexdec[101] = 14;
	mhexdec[102] = 15;
};

char* dechex (int dec) {
	if (dec == 0) {
		char *hex = calloc(2, sizeof(char));
		hex[0] = '0';
		hex[1] = '\0';
		return hex;
	}
	double dd;
	int i, l = 1;
	for (dd = (double) dec; dd >= 16; dd = dd / 16) {
		l++;
	}
	char *hex = calloc(l+1, sizeof(char));
// TODO Compute floor function
/**	if ((int)((char*)&dd)[6] < 0) {
		d = 1;
	}*/
	int d = floor(dd);
	for (i = 0; i < l; i++) {
		hex[i] = mdechex[d];
		if (i != l) {
			dd -= d;
			dd *= 16;
			d = floor(dd);
		}
	}
	hex[i] = '\0';
	return hex;
};

int ishexchar (const int *c) {
	return ( (*c > 47 && *c < 58) || (*c > 64 && *c < 71) || (*c > 96 && *c < 103) ) ? 1 : 0;
};

unsigned hexdec (const char *hex, const int s_hex) {
	if (s_hex == 0) {
		return 0;
	}
	unsigned d = 0, po, poi, i, c;
	for (i = 0; i < s_hex; i++) {
		c = (int) hex[i];
		if (ishexchar(&c) == 0) {
			errno = EINVAL;
			return 0;
		}
		po = s_hex-i-1;
		if (po) {
			for (po, poi = 16; po > 1; --po) {
				poi *= 16;
			}
		} else {
			poi = 1;
		}
		d += (mhexdec[c]) * poi;
	}
	return d;
};

char hexascii (const char *hex) {
	int i1 = (int) hex[0], i2 = (int) hex[1];
	if (ishexchar(&i1) && ishexchar(&i2)) {
		return (char) ( mhexdec[i1]*16 + mhexdec[i2] );
	} else {
		errno = EINVAL;
		return '\0';
	}
};

