// Program P5.2

#include <stdio.h>
#include <stdlib.h>
#define RogueValue -9999

typedef struct node {
	int num;
	struct node *next;
} Node, *NodePtr;

typedef struct stackType {
	NodePtr top;
} StackType, *Stack;

int main() {
	Stack initStack();
	int empty(Stack);
	void push(Stack, int);
	int pop(Stack);
	int n;
	Stack S = initStack();
	printf("Enter some integers, ending with 0\n");
	scanf("%d", &n);
	while (n != 0) {
		push(S, n);
		scanf("%d", &n);
	}
	printf("Numbers in reverse order\n");
	while (!empty(S))
		printf("%d ", pop(S));
	printf("\n");
} //end main

Stack initStack() {
	Stack sp = (Stack) malloc(sizeof(StackType));
	sp -> top = NULL;
	return sp;
}

int empty(Stack S) {
	return (S -> top == NULL);
}

void push(Stack S, int n) {
	NodePtr np = (NodePtr) malloc(sizeof(Node));
	np -> num = n;
	np -> next = S -> top;
	S -> top = np;
}

int pop(Stack S) {
	if (empty(S)) return RogueValue;
	int hold = S -> top -> num;
	NodePtr temp = S -> top;
	S -> top = S -> top -> next;
	free(temp);
	return hold;
}

