CC = gcc
RM = rm -rf
CP = cp

all: libhex.so

libhex.o: libhex.c
	$(CC) -c -fPIC $< -o $@

libhex.so: libhex.o
	$(CC) -shared -fPIC $< -o $@

install:
	$(CP) *.so /usr/lib/
	$(CP) *.h /usr/include/

clean:
	$(RM) *.o
	$(RM) *.so
	$(RM) ascii
	$(RM) dec
	$(RM) hex

hex: hex.c
	$(CC) $< -o $@ -lhex

dec: dec.c
	$(CC) $< -o $@ -lhex

ascii: ascii.c
	$(CC) $< -o $@ -lhex

test: hex dec ascii
	./hex 2014 1024 512 256 128 64 16 0
	./dec 7DE 400 200 100 80 40 10 0
	./ascii --table
