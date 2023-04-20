#include "Course.h"

Course::Course() {
	Date date;
	this->idCourse = "NULL";
	this->nameCourse = "NULL";
	this->schedule = date;
}
Course::~Course() {
	Date date;
	this->idCourse = "NULL";
	this->nameCourse = "NULL";
	this->schedule = date;
	this->roster.~Roster();
}
Course::Course(string id, string name, Date date) {
	idCourse = id;
	nameCourse = name;
	schedule = date;
}

ostream& operator<<(ostream& os, const Course& course) {
	os << "ID course: " << course.idCourse << endl;
	os << "Course's name: " << course.nameCourse << endl;
	os << "Schedule: " << course.schedule << endl;
	return os;
}
istream& operator>>(istream& is, Course& course) {
	cin.ignore();
	cout << "ID course: ";
	getline(is, course.idCourse);
	cout << "Course's name: ";
	getline(is, course.nameCourse);
	cout << "Schedule: ";
	is >> course.schedule;
	return is;
}

void Course::add_to_roster(string student_name) {
	this->roster.add_to_roster(student_name);
}

void Course::printSchedule() {
	this->roster.print_roster();
}