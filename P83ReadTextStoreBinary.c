//Program P8.3

#include <stdio.h>
int main() {
   FILE *intFile;
   int num;

   if ((intFile = fopen("num.bin", "wb")) == NULL) {
      printf("Cannot open file\n");
      return -1;
   }
   while (scanf("%d", &num) == 1)
      fwrite(&num, sizeof(int), 1, intFile);
   fclose (intFile);
} //end main
