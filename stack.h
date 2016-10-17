#include <stdlib.h>

typedef struct node {
	StackData data;
	struct node *next;
} Node, *NodePtr;

typedef struct stackType {
	NodePtr top;
} StackType, *Stack;

Stack initStack() {
	Stack sp = (Stack) malloc(sizeof(StackType));
	sp -> top = NULL;
	return sp;
}

int empty(Stack S) {
	return (S -> top == NULL);
}

void push(Stack S, StackData d) {
	NodePtr np = (NodePtr) malloc(sizeof(Node));
	np -> data = d;
	np -> next = S -> top;
	S -> top = np;
}

StackData pop(Stack S) {
	if (empty(S)) {
		printf("\nAttempt to pop an empty stack\n");
		exit(1);
	}
	StackData hold = S -> top -> data;
	NodePtr temp = S -> top;
	S -> top = S -> top -> next;
	free(temp);
	return hold;
}

StackData peek(Stack S) {
   if (!empty(S)) return S -> top -> data;
   printf("\nAttempt to peek at an empty stack\n");
   exit(1);
}
