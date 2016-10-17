// Program P8.1

//read numbers from a file and find their average; 0 ends the data
#include <stdio.h>
int main() {
   FILE * in = fopen("input.txt", "r");
   int num, sum = 0, n = 0;
   fscanf(in, "%d", &num);
   while (num != 0) {
      n = n + 1;
      sum = sum + num;
      fscanf(in, "%d", &num);
   }
   if (n == 0) printf("\nNo numbers entered\n");
   else {
      printf("\n%d numbers were entered\n", n);
      printf("The sum is %d\n", sum);
       printf("The average is %3.2f\n", (double) sum/n);
   }
   fclose(in);
} //end main
