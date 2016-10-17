// Program P6.1
#include <stdio.h>
#define MaxRow 20
#define MaxCol 20

int G[MaxRow][MaxCol];
int orgCount = 0;

int main() {
	void findOrg(int, int, int, int);
	void printOrg(FILE *, int m, int n);
	int i, j, m, n;
	FILE * in  = fopen("cell.in", "r");
	FILE * out = fopen("cell.out", "w");
	fscanf(in, "%d %d", &m, &n);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			fscanf(in, "%d", &G[i][j]);

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (G[i][j] == 1) {
				orgCount++;
				findOrg(i, j, m, n);
			}

	printOrg(out, m, n);
} //end main

void findOrg(int i, int j, int m, int n) {
	if (i < 0 || i >= m || j < 0 || j >= n) return; //outside of grid
	if (G[i][j] == 0 || G[i][j] > 1) return; //no cell or cell already seen
	// else G[i][j] = 1;
	G[i][j]= orgCount + 1; //so that this 1 is not considered again
	findOrg(i - 1, j, m, n);
	findOrg(i, j + 1, m, n);
	findOrg(i + 1, j, m, n);
	findOrg(i, j - 1, m, n);
} //end findOrg

void printOrg(FILE * out, int m, int n) {
	int i, j;
	fprintf(out, "\nNumber of organisms = %d\n", orgCount);
	fprintf(out, "\nPosition of organisms are shown here\n\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			if (G[i][j] > 1) fprintf(out, "%2d ", G[i][j] - 1);
				//organism labels are one more than they should be
      else fprintf(out, "%2d ", G[i][j]);
		fprintf(out, "\n");
	}
} //end printOrg
