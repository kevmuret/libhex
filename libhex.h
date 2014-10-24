#ifndef DEF_LIBHEX
#define DEF_LIBHEX

// Decimal to Hexadecimal

char* dechex (int dec, char *hex, int len, int fill);

// Hexadecimal to Decimal

void init_hexdec ();

int ishexchar (const int c);

//unsigned hex1dec (const char *hex);

//unsigned hex2dec (const char *hex);

unsigned hexdec (const unsigned char *hex, const int s_hex);

char hexascii (const unsigned char *hex);

#endif

