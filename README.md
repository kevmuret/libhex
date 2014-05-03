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

Use the flags <code>-lhex</code> and <code>-lm</code> to link with the libhex librairy and math librairy wich is used (<code>floor</code> and <code>pow</code> functions).

Fonctions
------

###dechex


Convert a Hexadecimal string in a Decimal unsigned int

Check for <code>errno == EINVAL</code>, if string contains invalid hexadecimal character.

###hexdec

Convert a Decimal int to an Hexadecimal string.

Note : Call the function init_hexdec() once before you convert decimal to hexadecimal.

Note : Don't forget to free the string that have been initialised using calloc.

TODO
======

- Shift the mhexdec array for using less memory.
- Initialize the mhexdec array.
- Make fonction for encoding/decoding characters based on ASCII Table.

