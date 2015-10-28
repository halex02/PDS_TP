CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g

.PHONY= clean re

EXEC= testCut

all : $(EXEC)

testCut : stringManipulation.o
	$(CC) $(CFLAGS) -o testCut testCut.c stringManipulation.o

stringManipulation.o : stringManipulation.c stringManipulation.h
	$(CC) $(CFLAGS) -c stringManipulation.c

clean :
	-rm *~ \#*#
	-rm *.o
	-rm $(EXEC)

re : clean all
