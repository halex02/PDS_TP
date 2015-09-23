CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g

.PHONY= clean re

all : prlimit maccess

prlimit : prlimit.c
	$(CC) $(CFLAGS) -o prlimit prlimit.c

maccess : maccess.c
	$(CC) $(CFLAGS) -o maccess maccess.c

clean :
	-rm *~ \#*#
	-rm *.o
	-rm prlimit maccess
re : clean all
