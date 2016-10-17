// Program P4.5

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int num;
	struct node *next;
} Node, *NodePtr;

int main() {
	void printList(NodePtr);
	NodePtr makeList(void);
	NodePtr merge(NodePtr, NodePtr);
	NodePtr A, B;

	printf("Enter numbers for the first list (0 to end)\n");
	A = makeList();
	printf("Enter numbers for the second list (0 to end)\n");
	B = makeList();
	printf("\nThe merged list is\n");
	printList(merge(A, B));
} //end main

NodePtr makeList() {
	NodePtr makeNode(int), np, top, last;
	int n;
	top = NULL;
	if (scanf("%d", &n) != 1) n = 0;
	while (n != 0) {
		np = makeNode(n);	//create a new node containing n
		if (top == NULL) top = np;	//set top if first node
		else last -> next = np;	//set last -> next for other nodes
		last = np;	//update last to  new node
		if (scanf("%d", &n) != 1) n = 0;
	}
	return top;
} //end makeList

NodePtr makeNode(int n) {
	NodePtr np = (NodePtr) malloc(sizeof (Node));
	np -> num = n;
	np -> next = NULL;
	return np;
} //end makeNode

void printList(NodePtr np) {
	while (np != NULL) {  // as long as there's a node
		printf("%d ", np -> num);
		np = np -> next;  // go on to the next node
	}
	printf("\n\n");
} //end printList

NodePtr merge(NodePtr A, NodePtr B) {
	NodePtr C = NULL, last = NULL;
	if (A == NULL) return B;
	if (B == NULL) return A;
	//both lists are non-empty
	while (A != NULL && B != NULL) {
		if (A -> num < B -> num) {
			if (C == NULL) C = A; else last -> next = A;
			last = A;
			A = A -> next ;
		}
		else {
			if (C == NULL) C = B; else last -> next = B;
			last = B;
			B = B -> next ;
		}
	} //end while
	if (A == NULL) last -> next = B;
	else last -> next = A;
	return C;
} //end merge
