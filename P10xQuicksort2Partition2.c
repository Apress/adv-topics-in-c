#include <stdio.h>

int main() {
   void quicksort2(int[], int, int);
   int num[] = {0, 53, 12, 98, 63, 18, 32, 80, 46, 72, 21};
   int n = 10;
   quicksort2(num, 1, n);
   for (int h = 1; h <= n; h++) printf("%d ", num[h]);
   printf("\n");
} //end main

void quicksort2(int A[], int lo, int hi) {
//sorts A[lo] to A[hi] in ascending order
   int partition2(int[], int, int);
   if (lo < hi) {
      int dp = partition2(A, lo, hi);
      quicksort2(A, lo, dp);
      quicksort2(A, dp+1, hi);
   }
} //end quicksort2

int partition2(int A[], int lo, int hi) {
//return dp such that A[lo..dp] <= A[dp+1..hi]
   void swap(int[], int, int);
   int pivot = A[lo];
   --lo; ++hi;
   while (lo < hi) {
      do --hi; while (A[hi] > pivot);
      do ++lo; while (A[lo] < pivot);
      if (lo < hi) swap(A, lo, hi);
   }
   return hi;
} //end partition2

void swap(int list[], int i, int j) {
//swap list[i] and list[j]
   int hold = list[i];
   list[i] = list[j];
   list[j] = hold;
} //end swap
