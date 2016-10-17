// Program P7.7

#include <stdio.h>
#include <stdlib.h>

int main() {
   int inS, inC = 0;
   double x, y;

   printf("\nHow many numbers to use? ");
   scanf("%d", &inS);

   srand(time(0));
   for (int h = 1; h <= inS; h++) {
      x = rand() / (RAND_MAX + 1.0);
      y = rand() / (RAND_MAX + 1.0);
      if (x * x + y * y <= 1) inC++;
   }
   printf("\nAn approximation to pi is %5.3f\n", 4.0 * inC / inS);
}
