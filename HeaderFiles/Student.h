#pragma once
#include"Date.h"
#include"Course.h"
#include"Schedule.h"
class Student
{
private:
	string idSV;
	string nameSV;
	Date birthDay;
	string addRess;
	Schedule schedule;
public:
	Student();
	~Student();
	string getID() {
		return idSV;
	}
	string getName() {
		return nameSV;
	}
	void add_to_schedule(string course_name);
	Student(string id, string name, Date birth, string address);
	friend ostream& operator<<(ostream& os, const Student& student);
	friend istream& operator>>(istream& is, Student& student);
	void printSchedule();
};

