#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MaxStudents 100
#define MaxNameLength 30
#define MaxNameBuffer MaxNameLength+1
typedef struct {
	char name[MaxNameBuffer];
	int age;
	char gender;
} Student;

int main() {
	Student pupil[MaxStudents];
	char aName[MaxNameBuffer];
	void getString(FILE *, char[]);
	int getData(FILE *, Student[]);
	int search(char[], Student[], int);
	void sort(Student[], int);
	void printStudent(Student);
	void getString(FILE *, char[]);

	FILE * in = fopen("input.txt", "r");
	if (in == NULL) {
		printf("Error opening file: %s.\n", strerror(errno));
		exit(1);
	}

	int numStudents = getData(in, pupil);
	if (numStudents == 0) {
		printf("No data supplied for students");
		exit(1);
	}

  printf("\n");
  for (int h = 0; h < numStudents; h++) printStudent(pupil[h]);
	printf("\n");

	getString(in, aName);
	while (strcmp(aName, "END") != 0) {
		int ans = search(aName, pupil, numStudents);
		if (ans == -1) printf("%s not found\n", aName);
		else printf("%s found at location %d\n", aName, ans);
		getString(in, aName);
	}

	sort(pupil, numStudents);
	printf("\n");
  for (int h = 0; h < numStudents; h++) printStudent(pupil[h]);
} //end main

void printStudent(Student t) {
	printf("Name: %s Age: %d Gender: %c\n", t.name, t.age, t.gender);
} //end printStudent

int getData(FILE *in, Student list[]) {
	char temp[MaxNameBuffer];
	void getString(FILE *, char[]);
	char readChar(FILE *);

  int n = 0;
  getString(in, temp);
	while (n < MaxStudents && strcmp(temp, "END") != 0) {
		strcpy(list[n].name, temp);
		fscanf(in, "%d", &list[n].age);
		list[n].gender = readChar(in);
		n++;
		getString(in, temp);
	}
	return n;
} //end getData

int search(char key[], Student list[], int n) {
//search for key in list[0] to list[n-1]
//if found, return the location; if not found, return -1
	for (int h = 0; h < n; h++)
		if (strcmp(key, list[h].name) == 0) return h;
	return -1;
} //end search

void sort(Student list[], int n) {
//sort list[0] to list[n-1] by name using an insertion sort
	for (int h = 1; h < n; h++) {
		Student temp = list[h];
		int k = h - 1;
		while (k >= 0 && strcmp(temp.name, list[k].name) < 0) {
			list[k + 1] = list[k];
			k = k - 1;
		}
    list[k + 1] = temp;
	} //end for
} //end sort

void getString(FILE * in, char str[]) {
//stores, in str, the next string within delimiters
// the first non-whitespace character is the delimiter
// the string is read from the file 'in'

	char ch, delim;
	int n = 0;
	str[0] = '\0';
	// read over white space
	while (isspace(ch = getc(in))) ; //empty while body
	if (ch == EOF) return;

	delim = ch;
	while (((ch = getc(in)) != delim) && (ch != EOF))
		str[n++] = ch;
	str[n] = '\0';
} // end getString

char readChar(FILE * in) {
	char ch;
	while (isspace(ch = getc(in))) ; //empty while body
	return ch;
} //end readChar
