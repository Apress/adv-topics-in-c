//Program P8.5


#include <stdio.h>

typedef struct partRecord {
   char partNum[7];
   char name[25];
   int amtInStock;
   double unitPrice;
} PartRecord;

int main() {
   FILE *ftxt, *fbin;
   PartRecord part;

   if ((ftxt = fopen("parts.txt", "r")) == NULL) {
      printf("Cannot open parts file\n");
      return  -1;
   }

   if ((fbin = fopen("parts.bin", "wb")) == NULL) {
      printf("Cannot create file\n");
      return -1;
   }

   while (fscanf(ftxt, "%s %s %d %lf", part.partNum, part.name,
                     &part.amtInStock, &part.unitPrice) == 4)
      if (fwrite(&part, sizeof(PartRecord), 1, fbin) != 1) {
         printf("Error in writing file\n");
         return -1;
      }

   fclose(ftxt);
   fclose(fbin);
} //end main
