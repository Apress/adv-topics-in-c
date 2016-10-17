#include <stdio.h>
#define MaxNumbers 10
int main() {
	void selectionSort(int [], int, int);
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
	selectionSort(num, 0, n-1);
	printf("\nThe sorted numbers are\n");
	for (int h = 0; h < n; h++) printf("%d ", num[h]);
	printf("\n");
}

void selectionSort(int list[], int lo, int hi) {
//sort list[lo] to list[hi] in ascending order
	int getSmallest(int[], int, int);
	void swap(int[], int, int);
	for (int h = lo; h < hi; h++) {
		int s = getSmallest(list, h, hi);
		swap(list, h, s);
	}
}

int getSmallest(int list[], int lo, int hi) {
//return location of smallest from list[lo..hi]
	int small = lo;
	for (int h = lo + 1; h <= hi; h++)
		if (list[h] < list[small]) small = h;
	return small;
}

void swap(int list[], int i, int j) {
//swap elements list[i] and list[j]
	int hold = list[i];
	list[i] = list[j];
	list[j] = hold;
}
