#pragma once
#include"Course.h"
#include"Student.h"
#include"Schedule.h"
#include"Roster.h"
#include<fstream>
#include<sstream>

class Registrar
{
private:
	vector<Course*> courses;
	vector<Student*> students;
public:
	~Registrar();
	void readCoursesFile();
	void studentRegister();
	void writeStudents();
	void readStudentsFile();
	void printCoursesWithStudent();
	void printScheduleOfStudent();


	void printCourses();
	void printStudents();
};

