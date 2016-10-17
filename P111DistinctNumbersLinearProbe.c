// Program P11.1

#include <stdio.h>
#include <stdlib.h>
#define MaxNumbers 20
#define N 23
#define Empty 0

int main() {
   FILE * in = fopen("numbers.in", "r");
   int h, key, num[N + 1];
   for (h = 1; h <= N; h++) num[h] = Empty;
   int distinct = 0;
   while (fscanf(in, "%d", &key) == 1) {
      int loc = key % N + 1;
      while (num[loc] != Empty && num[loc] != key) loc = loc % N + 1;
      if (num[loc] == Empty) { //key is not in the table
         if (distinct == MaxNumbers) {
            printf("\nTable full: %d not added\n", key);
            exit(1);
         }
         num[loc] = key;
         distinct++;
      }
   }
   printf("\nThere are %d distinct numbers\n", distinct);
   fclose(in);
} //end main

