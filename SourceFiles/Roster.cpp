#include "Roster.h"
Roster::~Roster() {
	while (studentName.size() > 0) {
		studentName.pop_back();
	}
}

void Roster::add_to_roster(string student_name) {
	if (this->studentName.size() <= 40) {
		studentName.push_back(student_name);
		cout << "Add student to roster successfully!" << endl;
	}
	else {
		cout << "Full roster!" << endl;
	}
}
void Roster::remove_from_roster(string student_name) {
	bool check = false;
	for (int i = 0; i < studentName.size(); i++)
	{
		if (studentName[i] == student_name) {
			studentName.erase(studentName.begin() + i - 1);
			check = true;
		}
	}
	if (check == true) {
		cout << "Remove " << student_name << " from roster successfully!" << endl;
	}
	else {
		cout << "Fail to remove " << student_name << "!" << endl;
	}
}
void Roster::print_roster() {
	if (studentName.size() == 0) {
		cout << "Empty roster!" << endl;
		return;
	}
	for (int i = 0; i < studentName.size(); i++)
	{
		cout << studentName[i] << ", ";
	}
	cout << endl;
}