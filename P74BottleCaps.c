// Program P7.4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxSim 20
#define MaxLetters 5

int main() {
   int capsThisSim, totalCaps = 0, doOneSim();

   srand(time(0));
   printf("\nSimulation  Caps collected\n\n");
   for (int sim = 1; sim <= MaxSim; sim++) {
      capsThisSim = doOneSim();
      printf("%6d %13d\n", sim, capsThisSim);
      totalCaps += capsThisSim;
   }
   printf("\nAverage caps per simulation: %d\n", totalCaps/MaxSim);
} //end main

int doOneSim() {
   int cap[MaxLetters], numCaps = 0, mango(int []), random(int, int);
   for (int h = 0; h < MaxLetters; h++) cap[h] = 0;
   while (!mango(cap)) {
      int c = random(1, 20);
      if (c <= 8) cap[0] = 1;
      else if (c <= 13) cap[1] = 1;
      else if (c <= 16) cap[2] = 1;
      else if (c <= 19) cap[3] = 1;
      else cap[4] = 1;
      numCaps++;
   }
   return numCaps;
} //end doOneSim

int mango(int cap[]) {
  for (int h = 0; h < MaxLetters; h++)
      if (cap[h] == 0) return 0;
   return 1;
} //end mango

int random(int m, int n) {
//returns a random integer from m to n, inclusive
   int offset = rand() / (RAND_MAX + 1.0) * (n - m + 1);
   return m + offset;
} //end random
