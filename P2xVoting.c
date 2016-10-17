#include <stdio.h>
#include <string.h>
#define MaxCandidates 7
#define MaxNameLength 30
#define MaxNameBuffer MaxNameLength+1

typedef struct  {
	char name[MaxNameBuffer];
	int numVotes;
} PersonData;
PersonData candidate[MaxCandidates];

typedef struct {
	int valid, spoilt;
} VoteCount;

int main() {
	void initialize(PersonData[], int, FILE *);
	VoteCount processVotes(PersonData[], int, FILE *, FILE *);
	void printResults(PersonData[], int, VoteCount, FILE *);

	PersonData candidate[MaxCandidates+1];
	VoteCount count;
	FILE *in = fopen("votes.txt", "r");
	FILE *out = fopen("results.txt", "w");

	initialize(candidate, MaxCandidates, in);
	count = processVotes(candidate, MaxCandidates, in, out);
//	sortByVote(candidate, 1, MaxCandidates);
//	sortByName(candidate, 1, MaxCandidates);
	printResults(candidate, MaxCandidates, count, out);

	fclose(in);
	fclose(out);
} //end main

void initialize(PersonData person[], int max, FILE *in) {
	char lastName[MaxNameBuffer];
	for (int h = 1; h <= max; h++) {
		fscanf(in, "%s %s", person[h].name, lastName);
		strcat(person[h].name, " ");
		strcat(person[h].name, lastName);
		person[h].numVotes = 0;
	}
} //end initialize

VoteCount processVotes(PersonData person[], int max,
						FILE *in, FILE *out) {
	VoteCount temp;
	temp.valid = temp.spoilt = 0;

	int v;
	fscanf(in, "%d", &v);
	while (v != 0) {
		if (v < 1 || v > max) {
			fprintf(out, "Invalid vote: %d\n", v);
			++temp.spoilt;
		}
		else {
			++person[v].numVotes;
			++temp.valid;
		}
		fscanf(in, "%d", &v);
	} //end while
	return temp;
}  //end processVotes

void printResults(PersonData person[], int max, VoteCount c, FILE *out) {
	int getLargest(PersonData[], int, int);
	fprintf(out, "\nNumber of voters: %d\n", c.valid + c.spoilt);
	fprintf(out, "Number of valid votes: %d\n", c.valid);
	fprintf(out, "Number of spoilt votes: %d\n", c.spoilt);
	fprintf(out, "\nCandidate       Score\n\n");

	for (int h = 1; h <= max; h++)
		fprintf(out, "%-15s %3d\n", person[h].name, person[h].numVotes);

	fprintf(out, "\nThe winner(s)\n");
	int win = getLargest(person, 1, max);
	int winningVote = person[win].numVotes;
	for (int h = 1; h <= max; h++)
		if (person[h].numVotes == winningVote)
				fprintf(out, "%s\n", person[h].name);
} //end printResults

int getLargest(PersonData person[], int lo, int hi) {
//returns the index of the highest vote from person[lo] to person[hi]
	int big = lo;
	for (int h = lo + 1; h <= hi; h++)
		if (person[h].numVotes > person[big].numVotes) big = h;
	return big;
} //end getLargest

void sortByVote(PersonData person[], int lo, int hi) {
//sort person[lo..hi] in descending order by numVotes
	PersonData insertItem;
	for (int h = lo + 1; h <= hi; h++) { // process person[lo+1] to person[hi]
		// insert person h in its proper position
		insertItem = person[h];
		int k = h -1;
		while (k >= lo && insertItem.numVotes > person[k].numVotes) {
				person[k + 1] = person[k];
				--k;
		}
		person[k + 1] = insertItem;
	}
} //end sortByVote

void sortByName(PersonData person[], int lo, int hi) {
//sort person[lo..hi] in alphabetical order by name
	PersonData insertItem;
	for (int h = lo + 1; h <= hi; h++) { // process person[lo+1] to person[hi]
		// insert person j in its proper position
		insertItem = person[h];
		int k = h -1;
		while (k > 0 && strcmp(insertItem.name, person[k].name) < 0) {
				person[k + 1] = person[k];
				--k;
		}
		person[k + 1] = insertItem;
	}
} //end sortByName
