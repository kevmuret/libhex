Installation
======

This will compile and install the files in your /usr/lib and /usr/include directories.

	make
	make install

Usage
======

Include the following librairy :

	<libhex.h>

Use the flags -lhex and -lm to link with the libhex librairy and math librairy wich is used (floor and pow functions).

Fonctions
======

dechex
------

Convert a Hexadecimal string in a Decimal unsigned int

hexdec
------

Convert a Decimal int to an Hexadecimal string.
Note : Call the function init_hexdec() once before you convert decimal to hexadecimal.
Note : Don't forget to free the string that have been initialised using calloc.

