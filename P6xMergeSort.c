#include <stdio.h>

#define MaxSize 20
main() {
   void mergeSort(int[], int, int);
   int num[] = {4,8,6,16,1,9,14,2,3,5,18,13,17,7,12,11,15,10};
   int n = 18;
   mergeSort(num, 0, n-1);
   for (int h = 0; h < n; h++) printf("%d ", num[h]);
   printf("\n\n");
}

void mergeSort(int A[], int lo, int hi) {
   void merge(int[], int, int, int);
   if (lo < hi) { //list contains at least 2 elements
      int mid = (lo + hi) / 2; //get the mid-point subscript
      mergeSort(A, lo, mid); //sort first half
      mergeSort(A, mid + 1, hi); //sort second half
      merge(A, lo, mid, hi); //merge sorted halves
   }
}

void merge(int A[], int lo, int mid, int hi) {
//A[lo..mid] and A[mid+1..hi] are sorted;
//merge the pieces so that A[lo..hi] are sorted
   int T[MaxSize];
   int i = lo;
   int j = mid + 1;
   int k = lo;
   while (i <= mid || j <= hi) {
      if (i > mid) T[k++] = A[j++];
      else if (j > hi) T[k++] = A[i++];
      else if (A[i] < A[j]) T[k++] = A[i++];
      else T[k++] = A[j++];
   }
   for (j = lo; j <= hi; j++) A[j] = T[j];
}

