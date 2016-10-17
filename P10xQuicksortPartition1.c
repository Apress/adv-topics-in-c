#include <stdio.h>

int main() {
   void quicksort(int[], int, int);
   int num[] = {0, 53, 12, 98, 63, 18, 32, 80, 46, 72, 21};
   int n = 10;
   quicksort(num, 1, n);
   for (int h = 1; h <= n; h++) printf("%d ", num[h]);
   printf("\n");
} //end main

void quicksort(int A[], int lo, int hi) {
//sorts A[lo] to A[hi] in ascending order
   int partition1(int[], int, int);
   if (lo < hi) {
      int dp = partition1(A, lo, hi);
      quicksort(A, lo, dp-1);
      quicksort(A, dp+1, hi);
   }
} //end quicksort

int partition1(int A[], int lo, int hi) {
//partition A[lo] to A[hi] using A[lo] as the pivot
   void swap(int[], int, int);
   int pivot = A[lo];
   int lastSmall = lo;
   for (int h = lo + 1; h <= hi; h++)
      if (A[h] < pivot) {
         ++lastSmall;
         swap(A, lastSmall, h);
      }
   //end for
   swap(A, lo, lastSmall);
   return lastSmall;  //return the division point
} //end partition1

void swap(int list[], int i, int j) {
//swap list[i] and list[j]
   int hold = list[i];
   list[i] = list[j];
   list[j] = hold;
}
