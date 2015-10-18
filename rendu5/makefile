CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g

.PHONY= clean re

EXEC=testMultif processusRally

all : $(EXEC)

multifourche.o : multifourche.c multifourche.h
	$(CC) $(CFLAGS) -c multifourche.c

power.o : power.c power.h
	$(CC) $(CFLAGS) -c power.c

forkfork.o : forkfork.c forkfork.h
	$(CC) $(CFLAGS) -c forkfork.c

processusRally: processusRally.c
	$(CC) $(CFLAGS) -o processusRally processusRally.c

testMultif : testMultif.c power.o multifourche.o
	$(CC) $(CFLAGS) -o testMultif testMultif.c power.o multifourche.o  

clean :
	-rm *~ \#*#
	-rm *.o
	-rm $(EXEC)

re : clean all
