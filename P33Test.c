//Program P3.3

#include <stdio.h>
int main() {
	void test(int val[], int max);
	int list[5];

	for (int h = 0; h < 5; h++) list[h] = h;
	test(list, 5);
	for (int h = 0; h < 5; h++) printf("%d ", list[h]);
	printf("\n");
} //end main

void test(int val[], int max) {
// add 25 to each of val[0] to val[max - 1]
	for (int h = 0; h < max; h++) val[h] += 25;
} //end test
