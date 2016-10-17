// Program P4.6

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node *next;
} Node, *NodePtr;

int main() {
	NodePtr curr, linkCircular(int), playGame(NodePtr, int, int);
   int n, m;

	do {
      printf("Enter number of children and length of count-out: ");
      scanf("%d %d", &n, &m);
	} while (n < 1 || m < 1);

	curr = linkCircular(n); //link children in a circular list
	curr = playGame(curr, n-1, m); //eliminate n-1 children
	printf("The winning child: %d\n", curr -> num);
} //end main

NodePtr makeNode(int n) {
	NodePtr np = (NodePtr) malloc(sizeof (Node));
	np -> num = n;
	np -> next = NULL;
	return np;
} //end makeNode

NodePtr linkCircular(int n) {
   //link n children in a circular list; return pointer to first child
   NodePtr first, np, makeNode(int);

   first = np = makeNode(1);  //first child
	for (int h = 2; h <= n; h++) { //link the others
      np -> next = makeNode(h);
      np = np -> next;
   }
	np -> next = first; //set last child to point to first
   return first;
} //end linkCircular

NodePtr playGame(NodePtr first, int x, int m) {
   NodePtr prev, curr = first;
   //eliminate x children
	for (int h = 1; h <= x; h++) {
      //curr is pointing at the first child to be counted;
      //count m-1 more to get to the mth child
      for (int c = 1; c < m; c++) {
         prev = curr;
         curr = curr -> next;
      }
      //delete the mth child
      prev -> next = curr -> next;
      free(curr);
      curr = prev -> next; //set curr to the child after the one eliminated
	}
	return curr;
} //end playGame
