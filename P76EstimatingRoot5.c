// Program P7.6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int maxCount, amountLess;
   double r;

   printf("\nHow many numbers to use? ");
   scanf("%d", &maxCount);

   srand(time(0));
   amountLess = 0;
   for (int h = 1; h <= maxCount; h++) {
      r = 2 + rand() / (RAND_MAX + 1.0);
      if (r * r < 5) ++amountLess;
   }
   printf("\nAn approximation to the square root of 5 is %5.3f\n",
               2 + (double) amountLess / maxCount);
} //end main
