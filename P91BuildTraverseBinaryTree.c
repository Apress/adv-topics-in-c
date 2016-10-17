// Program P9.1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxWordSize 20

typedef struct {
   char word[MaxWordSize+1];
} NodeData;

typedef struct treeNode {
   NodeData data;
   struct treeNode *left, *right;
} TreeNode, *TreeNodePtr;

typedef struct {
   TreeNodePtr root;
} BinaryTree;

int main() {
   TreeNodePtr buildTree(FILE *);
   void preOrder(TreeNodePtr);
   void inOrder(TreeNodePtr);
   void postOrder(TreeNodePtr);

   FILE * in = fopen("btree.in", "r");
   BinaryTree bt;
   bt.root = buildTree(in);
   printf("\nThe pre-order traversal is: ");
   preOrder(bt.root);
   printf("\n\nThe in-order traversal is: ");
   inOrder(bt.root);
   printf("\n\nThe post-order traversal is: ");
   postOrder(bt.root);
   printf("\n\n");
   fclose(in);
} // end main

TreeNodePtr buildTree(FILE * in) {
   char str[MaxWordSize+1];
   fscanf(in, "%s", str);
   if (strcmp(str, "@") == 0) return NULL;
   TreeNodePtr p = (TreeNodePtr) malloc(sizeof(TreeNode));
   strcpy(p -> data.word, str);
   p -> left = buildTree(in);
   p -> right = buildTree(in);
   return p;
} //end buildTree

void visit(TreeNodePtr node) {
   printf("%s ", node -> data.word);
} //end visit
void preOrder(TreeNodePtr node) {
   void visit(TreeNodePtr);
   if (node != NULL) {
      visit(node);
      preOrder(node -> left);
      preOrder(node -> right);
   }
} //end preOrder

void inOrder(TreeNodePtr node) {
   void visit(TreeNodePtr);
   if (node != NULL) {
      inOrder(node -> left);
      visit(node);
      inOrder(node -> right);
   }
} //end inOrder

void postOrder(TreeNodePtr node) {
   void visit(TreeNodePtr);
   if (node != NULL) {
      postOrder(node -> left);
      postOrder(node -> right);
      visit(node);
   }
} //end postOrder
