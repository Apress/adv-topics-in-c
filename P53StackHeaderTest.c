// Program P5.3
// For this program to work, the file stack.h (contents shown below)
// must be stored in the "include" folder of your compiler

#include <stdio.h>
#include <stack.h>

int main() {
	int n;
	Stack S = initStack();
	printf("Enter some integers, ending with 0\n");
	scanf("%d", &n);
	while (n != 0) {
		push(S, n);
		scanf("%d", &n);
	}
	printf("\nNumbers in reverse order\n");
	while (!empty(S))
		printf("%d ", pop(S));
	printf("\n");
}

// contents of stack.h, shown as comments. Uncomment to use.

//#include <stdlib.h>
//#define RogueValue -9999
//
//typedef struct node {
//	int num;
//	struct node *next;
//} Node, *NodePtr;
//
//typedef struct stackType {
//	NodePtr top;
//} StackType, *Stack;
//
//Stack initStack() {
//	Stack sp = (Stack) malloc(sizeof(StackType));
//	sp -> top = NULL;
//	return sp;
//}
//
//int empty(Stack S) {
//	return (S -> top == NULL);
//} //end empty
//
//void push(Stack S, int n) {
//	NodePtr np = (NodePtr) malloc(sizeof(Node));
//	np -> num = n;
//	np -> next = S -> top;
//	S -> top = np;
//} //end push
//
//int pop(Stack S) {
//	if (empty(S)) return RogueValue;
//	int hold = S -> top -> num;
//	NodePtr temp = S -> top;
//	S -> top = S -> top -> next;
//	free(temp);
//	return hold;
//} //end pop
