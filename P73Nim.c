// Program 7.3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int remain, maxPick, userPick, compPick;
   int bestPick(int, int), min(int, int);
   printf("\nNumber of matches on the table? ");
   scanf("%d", &remain);
   printf("Maximum pickup per turn? ");
   scanf("%d", &maxPick);
   printf("\nMatches remaining: %d\n", remain);

   srand(time(0));
   while (1) { //do forever...well, until the game ends
      do {
         printf("Your turn: ");
         scanf("%d", &userPick);
         if (userPick > remain)
            printf("Cannot pick up more than %d\n", min(remain, maxPick));
         else if (userPick < 1 || userPick > maxPick)
            printf("Invalid: must be between 1 and %d\n", maxPick);
      } while (userPick > remain || userPick < 1 || userPick > maxPick);
      remain = remain - userPick;
      printf("Matches remaining: %d\n", remain);
      if (remain == 0) {
         printf("You lose!!\n");
         exit(0);
      }
      if (remain == 1) {
         printf("You win!!\n");
         exit(0);
      }
      compPick = bestPick(remain, maxPick);
      printf("I pick up %d\n", compPick);
      remain = remain - compPick;
      printf("Matches remaining: %d\n", remain);
      if (remain == 0) {
         printf("You win!!\n");  exit(0);
      }
      if (remain == 1) {
         printf("I win!!\n");  exit(0);
      }
   } //end while(1)
} //end main

int bestPick(int remain, int maxPick) {
   int random(int, int);
   if (remain <= maxPick) return remain - 1; //put user in losing position
   int r = remain % (maxPick + 1);
   if (r == 0) return maxPick; //put user in losing position
   if (r == 1) return random(1, maxPick); //computer in losing position
   return r - 1; //put user in losing position
} //end bestPick

int min(int a, int b) {
   if (a < b) return a;
   return b;
} //end min

int random(int m, int n) {
//returns a random integer from m to n, inclusive
   int offset = rand() / (RAND_MAX + 1.0) * (n - m + 1);
   return m + offset;
} //end random
