#pragma once
#include"Date.h"
#include"Student.h"
#include"Roster.h"
class Course
{
private:
	string idCourse;
	string nameCourse;
	Date schedule;
	Roster roster;
public:
	Course();
	~Course();
	string getID() {
		return idCourse;
	}
	string getName(){
		return nameCourse;
	}
	Course(string id, string name, Date date);
	friend ostream& operator<<(ostream& os, const Course& course);
	friend istream& operator>>(istream& is, Course& course);
	void add_to_roster(string student_name);
	void printSchedule();
};

