// Program P7.5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxCounters 9

int main() {
   int  random(int, int), smallest(int[], int, int), max(int, int);
   int depart[MaxCounters + 1];
   int m, n, numCust, arriveTime, startServe, serveTime, waitTime;

   printf("\nHow many counters? ");
   scanf("%d", &n);
   printf("\nHow many customers? ");
   scanf("%d", &numCust);

   for (int c = 1; c <= n; c++) depart[c] = 0;
   srand(time(0));
   printf("\n                  Start          Service         Wait\n");
   printf("Customer Arrives Service Counter  Time   Departs Time\n\n");
   arriveTime = 0;
   for (int c = 1; c <= numCust; c++) {
      arriveTime += random(1, 5);
      m = smallest(depart, 1, n);
      startServe = max(arriveTime, depart[m]);
      serveTime = random(3, 10);
      depart[m] = startServe + serveTime;
      waitTime = startServe - arriveTime;
      printf("%5d %8d %7d %6d %7d %8d %5d\n",
         c, arriveTime, startServe, m, serveTime, depart[m], waitTime);
   } //end for
} //end main

int smallest(int list[], int lo, int hi) {
//returns the subscript of the smallest value in list
   int k = lo;
   for (int h = lo + 1; h <= hi; h++)
      if (list[h] < list[k]) k = h;
   return k;
} //end smallest

int max(int a, int b) {
   if (a > b) return a;
   return b;
} //end max

int random(int m, int n) {
//returns a random integer from m to n, inclusive
   int offset = rand() / (RAND_MAX + 1.0) * (n - m + 1);
   return m + offset;
} //end random

