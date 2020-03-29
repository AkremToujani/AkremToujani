
all: parsing.o checkUnitTest.o main.o
	gcc -o parsse parsing.o main.o -Wno-implicit -lcheck -lm -lpthread -lrt
	gcc parsing.o checkUnitTest.o -lcheck -lm -lpthread -lrt -o check_parsewrite_tests

parsing.o: parsing.c
	gcc -o parsing.o -c parsing.c -W -Wall -ansi -Wno-implicit

checkUnitTest.o: checkUnitTest.c parsing.h
	gcc -o checkUnitTest.o -c checkUnitTest.c -W -Wall -ansi -Wno-implicit

main.o: main.c parsing.h
	gcc -o main.o -c main.c -W -Wall -ansi -Wno-implicit

clean:
	rm parsse *.o
