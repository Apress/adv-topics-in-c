#include <string.h>

typedef struct {
	char name[31];
	int age;
	char gender;
} Student;

void sort(Student list[], int n) {
//sort list[0] to list[n-1] by name using an insertion sort
	Student temp;
	int k;
	for (int h = 1; h < n; h++) {
		Student temp = list[h];
		k = h - 1;
		while (k >= 0 && strcmp(temp.name, list[k].name) < 0) {
			list[k + 1] = list[k];
			k = k - 1;
		}
	}
	list[k + 1] = temp;
} //end sort
