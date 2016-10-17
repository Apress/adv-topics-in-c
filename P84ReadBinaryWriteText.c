//Program P8.4

#include <stdio.h>
int main() {
   FILE *intFile;
   int num;

   if ((intFile = fopen("num.bin", "rb")) == NULL) {
      printf("Cannot open file\n");
      return -1;
   }

   while (fread(&num, sizeof(int), 1, intFile) == 1)
      printf("%d\n", num);

   if (feof(intFile)) printf("\nEnd of list\n");
   else printf("\nError reading file\n");

   fclose(intFile);
} //end main
