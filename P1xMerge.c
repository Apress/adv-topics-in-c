#include <stdio.h>
int main () {
	int merge(int[], int, int[], int, int[]);
	int A[] = {21, 28, 35, 40, 61, 75};
	int B[] = {16, 25, 47, 54};
	int C[20];
	int n = merge(A, 6 , B, 4, C);
	for (int h = 0; h < n; h++) printf("%d ", C[h]);
	printf("\n\n");
} //end main

int merge(int A[], int m, int B[], int n, int C[]) {
	int i = 0; //i points to the first (smallest) number in A
	int j = 0; //j points to the first (smallest) number in B
	int k = -1; //k will be incremented before storing a number in C[k]
	while (i < m && j < n) {
		if (A[i] < B[j]) C[++k] = A[i++];
		else C[++k] = B[j++];
	}
	if (i == m) ///copy B[j] to B[n-1] to C
		for ( ; j < n; j++) C[++k] = B[j];
	else // j == n, copy A[i] to A[m-1] to C
		for ( ; i < m; i++) C[++k] = A[i];
	return m + n;
} //end merge
