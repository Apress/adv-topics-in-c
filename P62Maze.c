// Program P6.2
#include <stdio.h>
#define MaxRow 20
#define MaxCol 20

int m, n, sr, sc;
int G[MaxRow+1][MaxCol+1];

main() {
	void getData(FILE *);
	int findPath(int, int);
	void printMaze(FILE *);

	FILE * in = fopen("maze.in", "r");
	FILE * out = fopen("maze.out", "w");

	getData(in);
	if (findPath(sr, sc)) printMaze(out);
	else fprintf(out, "\nNo solution\n");

	fclose(in);
	fclose(out);
} //end main

void getData(FILE * in) {
	int r, c;
	fscanf(in, "%d %d %d %d", &m, &n, &sr, &sc);
	for (r = 1; r <= m; r++)
		for (c = 1; c <= n; c++)
			fscanf(in, "%d", &G[r][c]);
} //end getData

int findPath(int r, int c) {
	if (r < 1 || r > m || c < 1 || c > n) return 0;
	if (G[r][c] == 1) return 0; //into a wall
	if (G[r][c] == 2) return 0; //already considered

	// else G[r][c] = 0;
	G[r][c] = 2; //mark the path
	if (r == 1 || r == m || c == 1 || c == n) return 1;
	//path found - space located on the border of the maze

	if (findPath(r-1, c)) return 1;
	if (findPath(r, c+1)) return 1;
	if (findPath(r+1, c)) return 1;
	if (findPath(r, c-1)) return 1;
	G[r][c] = 0; //no path found; unmark
	return 0;
} //end findPath

void printMaze(FILE * out) {
	int r, c;
	for (r = 1; r <= m; r++) {
		for (c = 1; c <= n; c++)
			if (r == sr && c == sc) fprintf(out,"S");
			else if (G[r][c] == 0) fprintf(out," ");
			else if (G[r][c] == 1) fprintf(out,"#");
			else fprintf(out,"x");
		fprintf(out, "\n");
	}
} //end printMaze
