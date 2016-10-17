#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int left, right;
} StackData;

#include <stack.h>

int main() {
   void quicksort3(int[], int, int);
   int num[] = {0, 53, 12, 98, 63, 18, 32, 80, 46, 72, 21};
   int n = 10;
   quicksort3(num, 1, n);
   for (int h = 1; h <= n; h++) printf("%d ", num[h]);
   printf("\n");
} //end main

void quicksort3(int A[], int lo, int hi) {
   int partition2a(int[], int, int);
   StackData newStackData(int, int);
   Stack S = initStack();
   push(S, newStackData(lo, hi));
   int stackItems = 1, maxStackItems = 1;
   while (!empty(S)) {
      --stackItems;
      StackData d = pop(S);
      if (d.left < d.right) { //if the sublist is > 1 element
         int dp = partition2a(A, d.left, d.right);
         if (dp - d.left + 1 < d.right - dp) {  //compare lengths of sublists
            push(S, newStackData(dp+1, d.right));
            push(S, newStackData(d.left, dp));
         }
         else {
            push(S, newStackData(d.left, dp));
            push(S, newStackData(dp+1, d.right));
         }
         stackItems += 2;   //two items added to stack
      } //end if
      if (stackItems > maxStackItems) maxStackItems = stackItems;
   } //end while
   printf("Max stack items: %d\n\n", maxStackItems);
} //end quicksort3

int partition2a(int A[], int lo, int hi) {
//return dp such that A[lo..dp] <= A[dp+1..hi]
   void swap(int[], int, int);
   int random(int, int);
   //choose a random pivot
   swap(A, lo, random(lo, hi));
   int pivot = A[lo];
   --lo; ++hi;
   while (lo < hi) {
      do --hi; while (A[hi] > pivot);
      do ++lo; while (A[lo] < pivot);
      if (lo < hi) swap(A, lo, hi);
   }
   return hi;
} //end partition2a

void swap(int list[], int i, int j) {
//swap list[i] and list[j]
   int hold = list[i];
   list[i] = list[j];
   list[j] = hold;
} //end swap

int random(int m, int n) {
//returns a random integer from m to n, inclusive
   int offset = rand()/(RAND_MAX + 1.0) * (n - m + 1);
   return m + offset;
} //end random

StackData newStackData(int a, int b) {
   StackData temp;
   temp.left = a;
   temp.right = b;
   return temp;
} //end newStackData


