//Program P4.1

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int num;
	struct node *next;
} Node, *NodePtr;

int main() {
	void printList(NodePtr);
	NodePtr makeNode(int);
	int n;
	NodePtr top, np, last;

	top = NULL;
	if (scanf("%d", &n) != 1) n = 0;
	while (n != 0) {
		np = makeNode(n);	//create a new node containing n
		if (top == NULL) top = np;	//set top if first node
		else last -> next = np;	//set last -> next for other nodes
		last = np;	//update last to  new node
		if (scanf("%d", &n) != 1) n = 0;
	}
	printList(top);
} //end main

NodePtr makeNode(int n) {
	NodePtr np = (NodePtr) malloc(sizeof (Node));
	np -> num = n;
	np -> next = NULL;
	return np;
} //end makeNode

void printList(NodePtr np) {
	while (np != NULL) {  // as long as there's a node
		printf("%d\n", np -> num);
		np = np -> next;  // go on to the next node
	}
} //end printList
