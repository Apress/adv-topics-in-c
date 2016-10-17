#include <stdio.h>
#define MaxNumbers 10
int main() {
	void insertionSort(int [], int);
	void insertionSort1(int [], int, int);
	void insertionSort2(int [], int, int);
  int num[MaxNumbers];
	printf("Type up to %d numbers followed by 0\n", MaxNumbers);
	int n = 0, v;
	scanf("%d", &v);
	while (v != 0 && n < MaxNumbers) {
		num[n++] = v;
		scanf("%d", &v);
	}
	if (v != 0) {
    printf("More than %d numbers entered\n", MaxNumbers);
    printf("First %d used\n", MaxNumbers);
	}
	//n numbers are stored from num[0] to num[n-1]
	insertionSort2(num, 0, n-1);
	printf("\nThe sorted numbers are\n");
	for (int h = 0; h < n; h++) printf("%d ", num[h]);
	printf("\n");
}


void insertionSort(int list[], int n) {
//sort list[0] to list[n-1] in ascending order
	for (int h = 1; h < n; h++) {
		int key = list[h];
		int k = h - 1; //start comparing with previous item
		while (k >= 0 && key < list[k]) {
			list[k + 1] = list[k];
			--k;
		}
		list[k + 1] = key;
	} //end for
} //end insertionSort


void insertionSort1(int list[], int lo, int hi) {
//sort list[lo] to list[hi] in ascending order
	for (int h = lo + 1; h <= hi; h++) {
		int key = list[h];
		int k = h - 1; //start comparing with previous item
		while (k >= lo && key < list[k]) {
			list[k + 1] = list[k];
			--k;
		}
		list[k + 1] = key;
	} //end for
} //end insertionSort1

void insertInPlace(int newItem, int list[], int m, int n) {
//list[m] to list[n] are sorted
//insert newItem so that list[m] to list[n+1] are sorted
	int k = n;
	while (k >= m && newItem < list[k]) {
		list[k + 1] = list[k];
		--k;
	}
	list[k + 1] = newItem;
} //end insertInPlace


void insertionSort2(int list[], int lo, int hi) {
//sort list[lo] to list[hi] in ascending order
	void insertInPlace(int, int [], int, int);
	for (int h = lo + 1; h <= hi; h++)
		insertInPlace(list[h], list, lo, h - 1);
} //end insertionSort2


