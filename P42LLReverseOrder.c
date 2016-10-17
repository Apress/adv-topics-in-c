// Program P4.2

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int num;
	struct node *next;
} Node, *NodePtr;

//add new numbers at the head of the list
int main() {
	void printList(NodePtr);
	NodePtr makeNode(int);
	int n;
	NodePtr top, np;
	top = NULL;
	if (scanf("%d", &n) != 1) n = 0;
	while (n != 0) {
		np = makeNode(n);	//create a new node containing n
		np -> next = top;	//set link of new node to first node
		top = np;	//set top to point to new node
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
