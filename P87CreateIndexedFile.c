// Program P8.7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  PartNumSize  6
#define  MaxName  24
#define  MaxRecords  100

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
   IndexEntry index[MaxRecords + 1];
   void createMaster(char *, IndexEntry[], int);
   void saveIndex(char *, IndexEntry[], int);
   createMaster("parts.bin", index, MaxRecords);
   saveIndex("index.bin", index, MaxRecords + 1);
} //end main

void createMaster(char *fileName, IndexEntry index[], int maxRecords) {
// stores records in 'fileName';  caters for maxRecords index entries;
// sets index[0].recNum to the number of index entries actually used
   FILE *ftxt, *fbin;
   PartRecord part;
   int searchResult, search(char[], IndexEntry[], int);
   int numRecords = 0;

   if ((ftxt = fopen("parts.txt", "r")) == NULL) {
      printf("Cannot open parts file\n"); return;
   }

   if ((fbin = fopen("parts.bin", "wb")) == NULL) {
      printf("Cannot create file\n");
      return;
   }

   while (fscanf(ftxt, "%s %s %d %lf", part.partNum, part.name,
                        &part.amtInStock, &part.unitPrice) == 4) {
      searchResult = search(part.partNum, index, numRecords);
      if (searchResult > 0)
         printf("Duplicate part: %s ignored\n", part.partNum);
      else { //this is a new part number
         if (numRecords == maxRecords) {
            printf("Too many records: only %d allowed\n", maxRecords);
            exit(1);
         }
         //the index has room; shift entries to accommodate new part
         int j;
         for (j = numRecords; j >= -searchResult; j--)
               index[j + 1] = index[j];
         strcpy(index[-searchResult].partNum, part.partNum);
         index[-searchResult].recNum = ++numRecords;
         if (fwrite(&part, sizeof(PartRecord), 1, fbin) != 1) {
            printf("Error in writing file\n"); exit(1);
         }
         printf("%s %-11s %2d %5.2f\n", part.partNum, part.name,
                           part.amtInStock, part.unitPrice);
      }
   }
   index[0].recNum = numRecords;
   fclose(fbin);
} //end createMaster

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

void saveIndex(char *fileName, IndexEntry index[], int max) {
//save the index in fileName; max is the size of index.
   FILE *indexFile;
   if ((indexFile = fopen(fileName, "wb")) == NULL) {
      printf("Cannot create file %s. Index not saved\n", fileName);
      exit(1);
   }

   fwrite(&max, sizeof(int), 1, indexFile);  //save the index size first
   fwrite(index, sizeof(IndexEntry), max, indexFile); //save the index
   fclose(indexFile);
} //end saveIndex
