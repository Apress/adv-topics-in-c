// Program P8.8

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PartNumSize  6
#define MaxName  24
#define MaxRecords 100
typedef struct partRecord {
   char partNum[PartNumSize + 1];
   char name[MaxName + 1];
   int amtInStock; double unitPrice;
} PartRecord;
typedef struct indexEntry {
   char partNum[PartNumSize + 1];
   int recNum;
} IndexEntry;

int main() {
   FILE *partFile;
   IndexEntry index[MaxRecords + 1];
   void retrieveIndex(char *, IndexEntry[]);
   void retrieveRecords(IndexEntry[], FILE *);

   if ((partFile = fopen("parts.bin", "rb")) == NULL) {
      printf("Cannot open file\n");  return -1;
   }
   retrieveIndex("index.bin", index);
   retrieveRecords(index, partFile);
   fclose(partFile);
} //end main

void retrieveRecords(IndexEntry index[], FILE *pf) {
   char pnum[PartNumSize * 2]; //to cater for extra characters typed
   PartRecord part;
   int search(char[], IndexEntry[], int);

   int numRecords = index[0].recNum;
   printf("\nEnter a part number (E to end): ");
   scanf("%s", pnum);
   while (strcmp(pnum, "E") != 0) {
      int n = search(pnum, index, numRecords);
      if (n < 0) printf("Part not found\n");
      else {
         fseek(pf, (index[n].recNum - 1)*sizeof(PartRecord), SEEK_SET);
         fread(&part, sizeof(PartRecord), 1, pf);
         printf("\nPart number: %s\n", part.partNum);
         printf("Part name: %s\n", part.name);
         printf("Amount in stock: %d\n", part.amtInStock);
         printf("Price: $%3.2f\n", part.unitPrice);
      }
      printf("\nEnter a part number (E to end): ");
      scanf("%s", pnum);
   } //end while
} //end retrieveRecords

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
