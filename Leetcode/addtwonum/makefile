default: prog


linkedList.o: linkedList.c linkedList.h 
	gcc -Wall -std=c99 -c linkedList.c	

prog: linkedList.o
	gcc -Wall -std=c99  -o prog linkedList.o addTwoNum.c
		
clean:
	rm linkedList.o

cleanall: clean
	rm prog
