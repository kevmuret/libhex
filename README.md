Installation
======

This will compile and install the files in your /usr/lib and /usr/include directories.

	make
	make install

Make a test with :

	make test
	// Will compile and run two test executables
	//	./hex 2014 1024 512 256 128 64 16 0
	//	./dec 7DE 400 200 100 80 40 10 0

Clean output files with :

	make clean

Usage
======

Include the following librairy :

	<libhex.h>

Use the flags <code>-lhex</code> ~~and <code>-lm</code>~~ to link with the libhex librairy ~~and math librairy~~.

Fonctions
------

###char* dechex ( unsigned dec )


Convert a Hexadecimal string in a Decimal unsigned int

Check for <code>errno == EINVAL</code>, if string contains invalid hexadecimal character.

Note : Don't forget to free the string that have been initialised using calloc.

###void init_hexdec ( void )

Intitialize the decimal to hexadecimal conversion array.

###unsigned hexdec ( const unsigned char *hex, const int s_hex )

Convert a Decimal int to an Hexadecimal string.

Note : Call the function init_hexdec() once before you convert decimal to hexadecimal.

###char hexascii ( const unsigned char *hex )

Convert two characters length string to character according the ASCII Table.

Note : Call the function init_hexdec() once before you convert decimal to hexadecimal.

TODO
======

- Shift the mhexdec array for using less memory.
- Initialize the mhexdec array.
- Make fonction for encoding/decoding characters based on ASCII Table.

