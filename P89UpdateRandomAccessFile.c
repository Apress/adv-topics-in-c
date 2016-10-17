// Program P8.9

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PartNumSize  6
#define MaxName  24
#define MaxRecords 100

typedef struct partRecord {
   char partNum[PartNumSize + 1];
   char name[MaxName + 1];
   int amtInStock;
   double unitPrice;
} PartRecord;

typedef struct indexEntry {
   char partNum[PartNumSize + 1];
   int recNum;
} IndexEntry;

int main() {
   FILE *partFile;
   IndexEntry index[MaxRecords + 1];
   void retrieveIndex(char *, IndexEntry[]);
   void updateRecord(int, FILE *);
   int search(char[], IndexEntry[], int);
   char pnum[PartNumSize + 1];

   if ((partFile = fopen("parts.bin", "rb+")) == NULL) {
      printf("Cannot open file\n");
      return -1;
   }
   retrieveIndex("index.bin", index);
   int numRecords = index[0].recNum;

   printf("\nEnter a part number (E to end): ");
   scanf("%s", pnum);
   while (strcmp(pnum, "E") != 0) {
      int n = search(pnum, index, numRecords);
      if (n < 0) printf("Part not found\n");
      else updateRecord(index[n].recNum, partFile);
      printf("\nEnter a part number (E to end): ");
      scanf("%s", pnum);
   } // end while
   fclose(partFile);
} //end main

void updateRecord(int n, FILE *pf) {
//update record n in file pf
   PartRecord part;
   int amtSold;

   fseek(pf, (n - 1) * sizeof(PartRecord), SEEK_SET);
   fread(&part, sizeof(PartRecord), 1, pf);
   printf("Enter amount sold: ");
   scanf("%d", &amtSold);
   if (amtSold > part.amtInStock)
      printf("You have %d: cannot sell more, ignored\n", part.amtInStock);
   else {
      part.amtInStock -= amtSold;
      printf("Amount remaining: %d\n", part.amtInStock);
      fseek(pf, (n - 1) * sizeof(PartRecord), SEEK_SET);
      fwrite(&part, sizeof(PartRecord), 1, pf);
      printf("%s %-11s %2d %5.2f\n", part.partNum, part.name, part.amtInStock, part.unitPrice);
   } //end if
} //end updateRecord

void retrieveIndex(char *fileName, IndexEntry index[]) {
   FILE *indexFile;
   int maxRecords;

   if ((indexFile = fopen(fileName, "rb")) == NULL){
      printf("cannot open index file.\n");
      exit(1);
   }
   fread(&maxRecords, sizeof(int), 1,indexFile);
   fread(index, sizeof(IndexEntry), maxRecords, indexFile);
   fclose(indexFile);
} //end retrieveIndex

int search(char key[], IndexEntry list[], int n) {
//searches list[1..n] for key. If found, it returns the location; otherwise
//it returns the negative of the location in which key should be inserted.
   int lo = 1;  int hi = n;
   while (lo <= hi) {   // as long as more elements remain to consider
      int mid = (lo + hi) / 2;
      int cmp = strcmp(key, list[mid].partNum);
      if (cmp == 0) return mid;  // search succeeds
      if (cmp < 0) hi = mid - 1;    // key is 'less than' list[mid].partNum
      else lo = mid + 1;      // key is 'greater than' list[mid].partNum
   }
   return -lo;         // key not found; insert in location lo
} //end search
