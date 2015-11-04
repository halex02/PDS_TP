CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g

.PHONY= clean re

EXEC= stringManipulationTest

all : $(EXEC)

stringManipulationTest :  stringManipulation.o
	$(CC) $(CFLAGS) -o stringManipulationTest stringManipulationTest.c stringManipulation.o


stringManipulation.o : stringManipulation.c stringManipulation.h
	$(CC) $(CFLAGS) -c stringManipulation.c


commandParser.o : commandParser.h stringManipulation.o
	$(CC) $(CFLAGS) -c commandParser.c stringManipulation.o

clean :
	-rm *~ \#*#
	-rm *.o
	-rm $(EXEC)

re : clean all
