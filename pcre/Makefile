CFLAGS=-Iprefix/include
LDFLAGS=-Lprefix/lib -lpcre

pcre: pcre.c
	cc -s -static $(CFLAGS) pcre.c $(LDFLAGS) -o pcre

clean:
	rm pcre
