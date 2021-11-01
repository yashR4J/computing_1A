#include <stdio.h>
#include <stdlib.h>

typedef int age;
typedef char *name;

void incrementAges(age *studentAges, int size);
void printStudents(name *studentNames, age *studentAges, int size);

int main(int argc, char* argv[]) {
	int size = 6;
	name *studentNames = (name*)malloc(sizeof(name) * size);
	age *studentAges = (age*)malloc(sizeof(age) * size);

	studentNames[0] = "Frank";
	studentNames[1] = "Moni";
	studentNames[2] = "Jimmy";
	studentNames[3] = "Chen";
	studentNames[4] = "Navim";
	studentNames[5] = "Faraq";

	studentAges[0] = 18;
	studentAges[1] = 19;
	studentAges[2] = 20;
	studentAges[3] = 19;
	studentAges[4] = 18;
	studentAges[5] = 19;

	// Increment their ages because we want to increase their age
	incrementAges(studentAges, size);
	printStudents(studentNames, studentAges, size);

	free(studentNames);
	free(studentAges);
	studentNames = NULL;
	studentAges = NULL;

	return 0;
}

void incrementAges(age *studentAges, int size) {
	int i = 0;
	while (i < size) {
		studentAges[i] = studentAges[i] + 1;
		i++;
	}
}

void printStudents(name *studentNames, age *studentAges, int size) {
	int i = 0;
	while (i < size) {
		printf("Student %s is of age %d\n", studentNames[i], studentAges[i]);
		i++;
	}
}
