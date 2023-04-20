#include"Registrar.h"

int main() {
	Registrar reg;
	reg.readCoursesFile();
	reg.printCourses();
	reg.readStudentsFile();
	reg.printStudents();
	reg.writeStudents();

	reg.studentRegister();
	reg.studentRegister();
	reg.studentRegister();
	reg.studentRegister();
	reg.studentRegister();

	reg.printCoursesWithStudent();
	reg.printScheduleOfStudent();
}