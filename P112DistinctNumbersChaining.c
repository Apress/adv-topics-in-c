// Program P11.2

#include <stdio.h>
#include <stdlib.h>
#define N 13
#define Empty 0

typedef struct node {
   int num;
   struct node *next;
} Node, *NodePtr;

NodePtr newNode(int n) {
   NodePtr p = (NodePtr) malloc(sizeof(Node));
   p -> num = n;
   p -> next = NULL;
   return p;
}

int main() {
   int key, search(int, NodePtr[], int);
   void printList(NodePtr);
   FILE * in = fopen("numbers.in", "r");
   NodePtr hash[N+1];
   for (int h = 1; h <= N; h++) hash[h] = NULL;
   int distinct = 0;
   while (fscanf(in, "%d", &key) == 1)
      if (!search(key, hash, N)) distinct++;

   printf("\nThere are %d distinct numbers\n\n", distinct);
   for (int h = 1; h <= N; h++)
      if (hash[h] != NULL) {
         printf("hash[%d]:  ", h);
         printList(hash[h]);
      }
   fclose(in);
} //end main

int search(int inKey, NodePtr hash[], int n) {
//return 1 if inKey is found; 0, otherwise
//insert a new key in its appropriate list so list is in order
   NodePtr newNode(int);
   int k = inKey % n + 1;
   NodePtr curr = hash[k];
   NodePtr prev = NULL;
   while (curr != NULL && inKey > curr -> num) {
      prev = curr;
      curr = curr -> next;
   }
   if (curr != NULL && inKey == curr -> num) return 1; //found
   //not found; inKey is a new key; add it so list is in order
   NodePtr np = newNode(inKey);
   np -> next = curr;
   if (prev == NULL) hash[k] = np;
   else prev -> next = np;
   return 0;
} //end search

void printList(NodePtr top) {
   while (top != NULL) {
      printf("%2d ", top -> num);
      top = top -> next;
   }
   printf("\n");
} //end printList

