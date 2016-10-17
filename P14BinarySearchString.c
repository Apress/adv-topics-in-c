#include <stdio.h>
#include <string.h>
#define MaxNameSize 14
#define MaxNameBuffer MaxNameSize+1
#define MaxNames 8
int main () {
	int binarySearch(int, int, char [], int max, char [][max]);
	int n;
	char name[MaxNames][MaxNameBuffer] = {"Ali, Michael","Duncan, Denise",
			"Khan, Carol","Owen, David", "Ramdhan, Kamal",
			"Sawh, Anisa", "Singh, Krishna", "Taylor, Victor"};
	n = binarySearch(0, 7, "Ali, Michael", MaxNameBuffer, name);
	printf("%d\n", n);  //will print 0, location of Ali, Michael
	n = binarySearch(0, 7, "Taylor, Victor", MaxNameBuffer, name);
	printf("%d\n", n); //will print 7, location of Taylor, Victor
	n = binarySearch(0, 7, "Owen, David", MaxNameBuffer, name);
	printf("%d\n", n); //will print 3, location of Owen, David
	n = binarySearch(4, 7, "Owen, David", MaxNameBuffer, name);
	printf("%d\n", n); //will print -1, since Owen, David is not in locations 4 to 7
	n = binarySearch(0, 7, "Sandy, Cindy", MaxNameBuffer, name);
	printf("%d\n", n); //will print -1 since Sandy, Cindy is not in the list
} //end main

int binarySearch(int lo, int hi, char key[], int max, char list[][max]) {
//search for key from list[lo] to list[hi]
//if found, return its location; otherwise, return -1
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int cmp = strcmp(key, list[mid]);
		if (cmp == 0) return mid; // found
		if (cmp < 0) hi = mid - 1;
		else lo = mid + 1;
	}
	return -1; //lo and hi have crossed; key not found
} //end binarySearch
