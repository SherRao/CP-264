q3.exe : common.o queue.o stack.o expression.o expression_main.c
	gcc common.o queue.o stack.o expression.o expression_main.c -o q3.exe

common.o : common.c
	gcc -c common.c

queue.o : common.o queue.c
	gcc -c common.o queue.c

stack.o : common.o stack.c
	gcc -c common.o stack.c	

expression.o : common.o queue.o stack.o expression.c
	gcc -c common.o queue.o stack.o expression.c

run:
	q3.exe

clean :
	rm q3.exe common.o queue.o stack.o expression.o
