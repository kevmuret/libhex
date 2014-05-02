CC = gcc
RM = rm -rf
CP = cp

all: libhex.so

libhex.o: libhex.c
	$(CC) -c -fPIC $< -o $@ -lm

libhex.so: libhex.o
	$(CC) -shared -fPIC $< -o $@

install:
	$(CP) *.so /usr/lib/
	$(CP) *.h /usr/include/

clean:
	$(RM) *.o
	$(RM) *.so
