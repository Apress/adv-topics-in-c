// Program P8.6

#include <stdio.h>

typedef struct partRecord {
   char partNum[7];
   char name[25];
   int amtInStock;
   double unitPrice;
} PartRecord;

int main() {
   FILE *fbin;
   PartRecord part;
   int n;

   if ((fbin = fopen("parts.bin", "rb")) == NULL) {
      printf("Cannot open file\n");
      return  -1;
   }
   printf("Enter record number: ");
   scanf("%d", &n);
   while (n != 0) {
      fseek(fbin, (n - 1) * sizeof(PartRecord), SEEK_SET);
      fread(&part, sizeof(PartRecord), 1, fbin);

      printf("\nPart number: %s\n", part.partNum);
      printf("Part name: %s\n", part.name);
      printf("Amount in stock: %d\n", part.amtInStock);
      printf("Price: $%3.2f\n\n", part.unitPrice);

      printf("Enter record number: ");
      scanf("%d", &n);
   }
   fclose(fbin);
} //end main
