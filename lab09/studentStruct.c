// Last Modified by: Yash Raj
// Date last modified: 30/07/2020
// Declares/initialises a string array of names and a corresponding age 
// for students -> increments all ages by 1 -> prints out results 

#include <stdio.h>
#include <stdlib.h>

typedef int age;
typedef char* name;

struct studentInfo {
	int size;
	name *studentNames;
	age *studentAges;
};

typedef struct studentInfo StudentInfo;

void incrementAges(StudentInfo si);
void printStudents(StudentInfo si);

int main(int argc, char* argv[]) {

	StudentInfo student;
	
	student.size = 6;
	student.studentNames = (name*)malloc(sizeof(name) * student.size);
	student.studentAges = (age*)malloc(sizeof(age) * student.size);

	student.studentNames[0] = "Frank";
	student.studentNames[1] = "Moni";
	student.studentNames[2] = "Jimmy";
	student.studentNames[3] = "Chen";
	student.studentNames[4] = "Navim";
	student.studentNames[5] = "Faraq";

	student.studentAges[0] = 18;
	student.studentAges[1] = 19;
	student.studentAges[2] = 20;
	student.studentAges[3] = 19;
	student.studentAges[4] = 18;
	student.studentAges[5] = 19;

	// Increment their ages because we want to increase their age
	incrementAges(&student); 
	printStudents(student);

	free(student.studentNames);
	free(student.studentAges);
	student.studentNames = NULL;
	student.studentAges = NULL;

	return 0;
}

void incrementAges(StudentInfo *si) {
	int i = 0;
	while (i < si->size) {
		si->studentAges[i] = si->studentAges[i] + 1;
		i++;
	} 
}

void printStudents(StudentInfo si) {
	int i = 0;
	while (i < si.size) {
		printf("Student %s is of age %d\n", si.studentNames[i],
			 si.studentAges[i]);
		i++;
	}
}
