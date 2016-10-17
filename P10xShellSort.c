// Shell sort

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
int main() {
   void hsort(int[], int, int);
   int num[MaxSize + 1];
   int n = 0, number;
   FILE * in = fopen("shell.in", "r");

   int incr[] = {3, 8, 3, 1}; //first 3 is the number of increments

   while (fscanf(in, "%d", &number) == 1) {
      if (n < MaxSize) num[++n] = number;
      else {
         printf("\nArray too small\n");
         exit(1);
      }
   }
   //perform Shell sort with increments 8, 3 and 1
//   hsort(num, n, 8);
//   hsort(num, n, 3);
//   hsort(num, n, 1);

   for (int i = 1; i <= incr[0]; i++) hsort(num, n, incr[i]);

   for (int h = 1; h <= n; h++) printf("%d ", num[h]);
   printf("\n");
   fclose(in);
} //end main

void hsort(int A[], int n, int h) {
   for (int k = h + 1; k <= n; k++) {
      int j = k - h; //j will index elements k - h, k - 2h, k - 3h, etc
      int key = A[k];
      while (j > 0 && key < A[j]) {
         A[j + h] = A[j];
         j = j - h;
      }
      A[j + h] = key;
   }
} //end hsort
