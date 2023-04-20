#include "Student.h"

Student::Student() {
	Date date;
	this->idSV = "NULL";
	this->nameSV = "NULL";
	this->birthDay = date;
	this->addRess = "NULL";
}
Student::~Student() {
	Date date;
	this->idSV = "NULL";
	this->nameSV = "NULL";
	this->birthDay = date;
	this->addRess = "NULL";
	this->schedule.~Schedule();
}
Student::Student(string id, string name, Date birth, string address) {
	idSV = id;
	nameSV = name;
	birthDay = birth;
	addRess = address;
}
ostream& operator<<(ostream& os, const Student& student) {
	os << "ID student: " << student.idSV << endl;
	os << "Student name: " << student.nameSV << endl;
	os << "Birthday: " << student.birthDay << endl;
	os << "Address: " << student.addRess << endl;
	return os;
}
istream& operator>>(istream& is, Student& student) {
	return is;
}

void Student::add_to_schedule(string course_name) {
	this->schedule.add_to_schedule(course_name);
}
void Student::printSchedule() {
	schedule.print_schedule();
}
