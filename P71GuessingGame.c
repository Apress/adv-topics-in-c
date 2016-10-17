// Program P7.1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int answer, guess, random(int, int);

   printf("\nI have thought of a number from 1 to 100.\n");
   printf("Try to guess what it is.\n\n");

   srand(time (0));
   answer = random(1, 100);

   printf("Your guess? ");
   scanf("%d", &guess);
   while (guess != answer && guess != 0) {
      if (guess < answer) printf("Too low\n");
      else printf("Too high\n");
      printf("Your guess? ");
      scanf("%d", &guess);
   }
   if (guess == 0) printf("Sorry, answer is %d\n", answer);
   else printf("Congratulations, you've got it!\n");
} //end main

int random(int m, int n) {
//returns a random integer from m to n, inclusive
   int offset = rand() / (RAND_MAX + 1.0) * (n - m + 1);
   return m + offset;
} //end random
