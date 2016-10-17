#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MaxWords 50
#define MaxLength 10
#define MaxWordBuffer MaxLength+1
int main() {
	int getWord(FILE *, char[]);
	int binarySearch(int, int, char [], int max, char [][max]);
	void addToList(char[], int max, char [][max], int[], int, int);
	void printResults(FILE *, int max, char [][max], int[], int);
	char wordList[MaxWords][MaxWordBuffer], word[MaxWordBuffer];
	int frequency[MaxWords], numWords = 0;

	FILE * in = fopen("passage.txt", "r");
	if (in == NULL){
		printf("Cannot find file\n");
	  exit(1);
	}

	FILE * out = fopen("output.txt", "w");
	if (out == NULL){
		printf("Cannot create output file\n");
	  exit(2);
	}

	for (int h = 1; h <= MaxWords ; h++) frequency[h] = 0;

	while (getWord(in, word) != 0) {
		int loc = binarySearch (0, numWords-1, word, MaxWordBuffer, wordList);
		if (strcmp(word, wordList[loc]) == 0) ++frequency[loc]; //word found
		else //this is a new word
			if (numWords < MaxWords) { //if table is not full
				addToList(word, MaxWordBuffer, wordList, frequency, loc, numWords-1);
				++numWords;
			}
			else fprintf(out, "'%s' not added to table\n", word);
	}
	printResults(out, MaxWordBuffer, wordList, frequency, numWords);
} // end main

int getWord(FILE * in, char str[]) {
// stores the next word, if any, in str; word is converted to lowercase
// returns 1 if a word is found; 0, otherwise
	char ch;
	int n = 0;
	// read over white space
	while (!isalpha(ch = getc(in)) && ch != EOF) ; //empty while body
	if (ch == EOF) return 0;
	str[n++] = tolower(ch);
	while (isalpha(ch = getc(in)) && ch != EOF)
		if (n < MaxLength) str[n++] = tolower(ch);
	str[n] = '\0';
	return 1;
} // end getWord

int binarySearch(int lo, int hi, char key[], int max, char list[][max]) {
//search for key from list[lo] to list[hi]
//if found, return its location;
//if not found, return the location in which it should be inserted
//the calling program will check the location to determine if found
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int cmp = strcmp(key, list[mid]);
		if (cmp == 0) return mid; // found
		if (cmp < 0) hi = mid - 1;
		else lo = mid + 1;
	}
	return lo; //not found; should be inserted in location lo
} //end binarySearch

void addToList(char item[], int max, char list[][max], int freq[], int p, int n) {
//adds item in position list[p]; sets freq[p] to 1
//shifts list[n] down to list[p] to the right
	for (int h = n; h >= p; h--) {
		strcpy(list[h+1], list[h]);
		freq[h+1] = freq[h];
	}
	strcpy(list[p], item);
	freq[p] = 1;
} //end addToList

void printResults(FILE *out, int max, char list[][max], int freq[], int n) {
	fprintf(out, "\nWords        Frequency\n\n");
	for (int h = 0; h < n; h++)
		fprintf(out, "%-15s %2d\n", list[h], freq[h]);
} //end printResults
