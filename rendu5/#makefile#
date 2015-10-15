CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g

.PHONY= clean re

all : testMultif

multifourche.o : multifourche.c multifourche.h
	$(CC) $(CFLAGS) -c multifourche.c

power.o : power.c power.h
	$(CC) $(CFLAGS) -c power.c

main : main.c multifourche.o power.o
	$(CC) $(CFLAGS) -o main main.c

testMultif : testMultif.c power.o multifourche.o
	$(CC) $(CFLAGS) -o testMultif testMultif.c power.o multifourche.o  

clean :
	-rm *~ \#*#
	-rm *.o

re : clean all
