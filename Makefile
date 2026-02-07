PREFIX ?= /usr/local
CC ?= gcc
CFLAGS = -O2 -march=native -Wno-unused-result -Wno-incompatible-pointer-types
LDFLAGS = -lX11

output: dwmblocks.c blocks.def.h blocks.h
	${CC} ${CFLAGS} dwmblocks.c $(LDFLAGS) -o dwmblocks

blocks.h:
	cp blocks.def.h $@

clean:
	rm -f *.o *.gch dwmblocks blocks.h

install: output
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m 0755 dwmblocks $(DESTDIR)$(PREFIX)/bin/dwmblocks

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/dwmblocks
