// Program P10.1

#include <stdio.h>
#include <stdlib.h>
#define MaxHeapSize 100
int main() {
   void siftUp(int[], int);
   int num[MaxHeapSize + 1];
   int n = 0, number;
   FILE * in = fopen("heap.in", "r");

   while (fscanf(in, "%d", &number) == 1) {
      if (n < MaxHeapSize) { //check if array has room
         num[++n] = number;
         siftUp(num, n);
      }
      else {
         printf("\nArray too small\n");
         exit(1);
      }
   }
   for (int h = 1; h <= n; h++) printf("%d ", num[h]);
   printf("\n");
   fclose(in);
} //end main

void siftUp(int heap[], int n) {
//sifts up the value in heap[n] so that heap[1..n] contains a heap
   int siftItem = heap[n];
   int child = n;
   int parent = child / 2;
   while (parent > 0) {
      if (siftItem <= heap[parent]) break;
      heap[child] = heap[parent]; //move down parent
      child = parent;
      parent = child / 2;
   }
   heap[child] = siftItem;
} //end siftUp
