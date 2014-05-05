#ifndef DEF_LIBHEX
#define DEF_LIBHEX

// Decimal to Hexadecimal

char* dechex (int dec);

// Hexadecimal to Decimal

void init_hexdec ();

int ishexchar (const int *c);

//unsigned hex1dec (const char *hex);

//unsigned hex2dec (const char *hex);

unsigned hexdec (const char *hex, const int s_hex);

char hexascii (const char *hex);

#endif

