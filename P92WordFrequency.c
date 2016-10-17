// Program P9.2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MaxWordSize 20

typedef struct {
   char word[MaxWordSize+1];
   int freq;
} NodeData;

typedef struct treeNode {
   NodeData data;
   struct treeNode *left, *right;
} TreeNode, *TreeNodePtr;

typedef struct {
   TreeNodePtr root;
} BinaryTree;

int main() {
   int getWord(FILE *, char[]);
   TreeNodePtr newTreeNode(NodeData);
   NodeData newNodeData(char[], int);
   TreeNodePtr findOrInsert(BinaryTree, NodeData);
   void inOrder(FILE *, TreeNodePtr);

   char word[MaxWordSize+1];

   FILE * in = fopen("wordFreq.in", "r");
   FILE * out = fopen("wordFreq.out", "w");

   BinaryTree bst;
   bst.root = NULL;

   while (getWord(in, word) != 0) {
      if (bst.root == NULL)
         bst.root = newTreeNode(newNodeData(word, 1));
      else {
         TreeNodePtr node = findOrInsert(bst, newNodeData(word, 0));
         node -> data.freq++;
      }
   }

   fprintf(out, "\nWords        Frequency\n\n");
   inOrder(out, bst.root); fprintf(out, "\n\n");
   fclose(in);
   fclose(out);
} // end main

int getWord(FILE * in, char str[]) {
// stores the next word, if any, in str; word is converted to lowercase
// returns 1 if a word is found; 0, otherwise
   char ch;
   int n = 0;
   // read over non-letters
   while (!isalpha(ch = getc(in)) && ch != EOF) ; //empty while body
   if (ch == EOF) return 0;
   str[n++] = tolower(ch);
   while (isalpha(ch = getc(in)) && ch != EOF)
      if (n < MaxWordSize) str[n++] = tolower(ch);
   str[n] = '\0';
   return 1;
} // end getWord

TreeNodePtr findOrInsert(BinaryTree bt, NodeData d) {
//searches for d; if found, return pointer to node containing d
//else insert a node containing d and return pointer to new node
   TreeNodePtr newTreeNode(NodeData);

   if (bt.root == NULL) return newTreeNode(d);
   TreeNodePtr curr = bt.root;
   int cmp;
   while ((cmp = strcmp(d.word, curr -> data.word)) != 0) {
      if (cmp < 0) { //try left
         if (curr -> left == NULL) return curr -> left = newTreeNode(d);
         curr = curr -> left;
      }
      else { //try right
         if (curr -> right == NULL) return curr -> right = newTreeNode(d);
         curr = curr -> right;
      }
   }
   //d is in the tree; return pointer to the node
   return curr;
} //end findOrInsert

TreeNodePtr newTreeNode(NodeData d) {
   TreeNodePtr p = (TreeNodePtr) malloc(sizeof(TreeNode));
   p -> data = d;
   p -> left = p -> right = NULL;
   return p;
} //end newTreeNode

void inOrder(FILE * out, TreeNodePtr node) {
   if (node!= NULL) {
      inOrder(out, node -> left);
      fprintf(out, "%-15s %2d\n", node -> data.word, node -> data.freq);
      inOrder(out, node -> right);
   }
} //end inOrder

NodeData newNodeData(char str[], int n) {
   NodeData temp;
   strcpy(temp.word, str);
   temp.freq = n;
   return temp;
} //end newNodeData
