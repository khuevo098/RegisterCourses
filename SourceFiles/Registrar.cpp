#include "Registrar.h"


Registrar::~Registrar() {
	this->courses.~vector();
	this->students.~vector();
}
void Registrar::readCoursesFile() {
	ifstream file;
	file.open("Courses.txt", ios::in);
	if (file.is_open()) {
		string tempLine;
		while (getline(file, tempLine)) {
			string id, name, dateDay, dateMonth, dateYear;
			stringstream ss(tempLine);
			getline(ss, id, ',');
			getline(ss, name, ',');
			getline(ss, dateYear, '-');
			getline(ss, dateMonth, '-');
			getline(ss, dateDay, '.');

			
			int day, month, year;
			day = stoi(dateDay);
			month = stoi(dateMonth);
			year = stoi(dateYear);

			Date date(day, month, year);

			Course* course = new Course(id, name, date);

			this->courses.push_back(course);
		}
	}
	else {
		cout << "Fail to open file to read." << endl;
	}
	file.close();
}


void Registrar::printCourses() {
	for (int i = 0; i < courses.size(); i++)
	{
		cout << *courses[i] << endl;
	}
}

void Registrar::studentRegister() {
	bool check = false;
	string idStudent, idCourse;
	cout << "Press ENTER!" << endl;
	cin.ignore();
	cout << "Register Course" << endl;
	cout << "Student ID: ";
	getline(cin, idStudent);
	cout << "Course ID: ";
	getline(cin, idCourse);
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->getID() == idStudent) {
			for (int j = 0; j < courses.size(); j++)
			{
				if (courses[j]->getID() == idCourse) {
					students[i]->add_to_schedule(courses[j]->getName());
					courses[j]->add_to_roster(students[i]->getName());
					check = true;
					break;
				}
			}
		}
		if (check == true) {
			break;
		}
	}

	if (check == true) {
		cout << "Register for student successfully!" << endl;
	}
	else {
		cout << "Fail to register course for student" << endl;
	}

}
void Registrar::writeStudents() {
	if (students.size() == 0) {
		cout << "Empty student!" << endl;
		return;
	}
	ofstream file;
	file.open("Students_Out.txt", ios::out);
	if (file.is_open()) {
		file << "Total of students: " << students.size() << endl;
		for (int i = 0; i < students.size(); i++)
		{
			file << "Student " << i + 1 << ": " << endl;
			file << *students[i];
			file << "==========================================" << endl;
		}
	}
	else {
		cout << "Fail to open file to write." << endl;
	}
	file.close();
}
void Registrar::readStudentsFile() {
	ifstream file;
	file.open("Students.txt", ios::in);
	if (file.is_open()) {
		string tempLine;
		while (getline(file, tempLine)) {
			string id, name, dateDay, dateMonth, dateYear, address;
			stringstream ss(tempLine);
			getline(ss, id, ',');
			getline(ss, name, ',');
			getline(ss, dateDay, '/');
			getline(ss, dateMonth, '/');
			getline(ss, dateYear, ',');
			getline(ss, address, '.');

			int day, month, year;
			day = stoi(dateDay);
			month = stoi(dateMonth);
			year = stoi(dateYear);

			Date date(day, month, year);

			Student* student = new Student(id, name, date, address);

			this->students.push_back(student);
		}
	}
	else {
		cout << "Fail to open file to read." << endl;
	}
	file.close();
}

void Registrar::printStudents() {
	for (int i = 0; i < students.size(); i++)
	{
		cout << *students[i] << endl;
	}
}


void Registrar::printCoursesWithStudent() {
	cout << "COURSES WITH STUDENTS'S NAME" << endl;
	for (int i = 0; i < courses.size(); i++)
	{
		cout << "Course: " << courses[i]->getName() << endl;
		cout << "Students: ";
		courses[i]->printSchedule();
		cout << "---------------------------------------------" << endl;
	}
	cout << endl;
}

void Registrar::printScheduleOfStudent() {
	cout << "SCHEDULE OF STUDENTS" << endl;
	for (int i = 0; i < students.size(); i++)
	{
		cout << "Student: " << students[i]->getName() << endl;
		cout << "Schedule: ";
		students[i]->printSchedule();
		cout << "---------------------------------------------" << endl;
	}
	cout << endl;
}