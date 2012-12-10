CC=gcc
SRCS=pidgin-awn-plugin.c
OBJS=pidgin-awn-plugin.o

all:	gaim_awn.so
	
$(OBJS): ${SRCS}
	$(CC) -fPIC -Wall -c $(SRCS) -o ${OBJS} -DVERSION=\"`date "+%Y%m-%d_%R"`\" `pkg-config --cflags gtk+-2.0 pidgin purple atk cairo pango glib-2.0 dbus-1`

clean:
	rm pidgin-awn-plugin.so *.o
	
gaim_awn.so: $(OBJS)
	$(CC) -shared -Wl,-soname,pidgin-awn-plugin.so -o pidgin-awn-plugin.so $(OBJS)

install: pidgin-awn-plugin.so
	mkdir -p ~/.purple/plugins/pidgin-awn-plugin
	cp pidgin-awn-plugin.so ~/.purple/plugins/
	cp ./icon/*.png ~/.purple/plugins/pidgin-awn-plugin/

uninstall:
	rm -rf ~/.purple/plugins/pidgin-awn-plugin/
	rm -f ~/.purple/plugins/pidgin-awn-plugin.so

package:
	tar cvzf pidgin-awn-plugin-commit-`git log -1 --pretty=oneline origin/master | sed -E "s/^([^[:space:]]+).*/\1/"`.tar.gz pidgin-awn-plugin.c pidgin-awn-plugin.so Makefile
