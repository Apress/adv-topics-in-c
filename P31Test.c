// Program P3.1

#include <stdio.h>
int main() {
	void test(int);
	int n = 14;
	printf("%d\n", n);	// before calling test
	test(n);
	printf("%d\n", n);	// after return from test
} //end main

void test(int a) {
	a = a + 6;
	printf("%d\n", a);	// within test
} //end test
