Installation
======

This will compile and install the files in your /usr/lib and /usr/include directories.

	make
	make install

Clean output files with :

	make clean

Usage
======

Include the following librairy :

	<libhex.h>

Use the flags <code>-lhex</code> and <code>-lm</code> to link with the libhex librairy and math librairy.

Fonctions
------

###dechex


Convert a Hexadecimal string in a Decimal unsigned int

Check for <code>errno == EINVAL</code>, if string contains invalid hexadecimal character.

Note : Don't forget to free the string that have been initialised using calloc.

###hexdec

Convert a Decimal int to an Hexadecimal string.

Note : Call the function init_hexdec() once before you convert decimal to hexadecimal.

TODO
======

- Shift the mhexdec array for using less memory.
- Initialize the mhexdec array.
- Make fonction for encoding/decoding characters based on ASCII Table.

