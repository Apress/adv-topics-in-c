#include <stdio.h>
#include <string.h>
#define MaxNameSize 14
#define MaxNameBuffer MaxNameSize+1
#define MaxNames 8
int main() {
	void parallelSort(int, int, int max, char [][max], int[]);
	char name[MaxNames][MaxNameBuffer] = {"Taylor, Victor", "Duncan, Denise",
			"Ramdhan, Kamal", "Singh, Krishna", "Ali, Michael",
			"Sawh, Anisa", "Khan, Carol", "Owen, David" };
  int id[MaxNames] = {3050,2795,4455,7824,6669,5000,5464,6050};

	parallelSort(0, MaxNames-1, MaxNameBuffer, name, id);
	printf("\nThe sorted names and IDs are\n\n");
	for (int h = 0; h < MaxNames; h++) printf("%-18s %d\n", name[h], id[h]);
} //end main

void parallelSort(int lo, int hi, int max, char list[][max], int id[]) {
//Sort the names in list[lo] to list[hi] in alphabetical order, ensuring that
//each name remains with its original id number.
//The maximum string size is max - 1 (one char taken up by \0).
  char key[max];
	for (int h = lo + 1; h <= hi; h++) {
		strcpy(key, list[h]);
		int m = id[h];  // extract the id number
		int k = h - 1; //start comparing with previous item
		while (k >= lo && strcmp(key, list[k]) < 0) {
			strcpy(list[k + 1], list[k]);
			id[k+ 1] = id[k];  // move up id number when we move a name
			--k;
		}
		strcpy(list[k + 1], key);
		id[k + 1] = m; // store the id number in the same position as the name
	} //end for
} //end parallelSort
