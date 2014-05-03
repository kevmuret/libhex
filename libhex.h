#ifndef DEF_LIBHEX
#define DEF_LIBHEX

// Decimal to Hexadecimal

//char mdechex[16] = "0123456789ABCDEF";

char* dechex (int dec);

// Hexadecimal to Decimal

//int mhexdec[103];

void init_hexdec ();

int ishexchar (const int *c);

unsigned hex1dec (const char *hex);

unsigned hex2dec (const char *hex);

unsigned hexdec (const char *hex, const int s_hex);

#endif

