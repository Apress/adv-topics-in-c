//Program P5.4

#include <stdio.h>

typedef struct {
	char ch;
} StackData;

#include <stack.h>

int main() {
	StackData temp;
	char c;
	Stack S = initStack();
	printf("Type some data and press Enter\n");
	while ((c = getchar()) != '\n') {
		temp.ch = c;
		push(S, temp);
	}
	printf("\nData in reverse order\n");
	while (!empty(S))
		putchar(pop(S).ch);
	putchar('\n');
} //end main
