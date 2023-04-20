#include "Schedule.h"

Schedule::~Schedule() {
	while (this->courseName.size() > 0) {
		courseName.pop_back();
	}
}

void Schedule::add_to_schedule(string course_name) {
	if (courseName.size() <= 5) {
		courseName.push_back(course_name);
		cout << "Add course to schedule successfully!" << endl;
	}
	else {
		cout << "Full schedule!" << endl;
	}
}
void Schedule::remove_from_schedule(string course_name) {
	bool check = false;
	for (int i = 0; i < courseName.size(); i++)
	{
		if (courseName[i] == course_name) {
			courseName.erase(courseName.begin() + i - 1);
			check = true;
		}
	}
	if (check == true) {
		cout << "Remove " << course_name << " course from student's schedule successfull! " << endl;
	}
	else {
		cout << "Fail to remove " << course_name << " from student's schedule." << endl;
	}
}
void Schedule::print_schedule() {
	if (courseName.size() == 0) {
		cout << "Empty schedule" << endl;
		return;
	}

	for (int i = 0; i < courseName.size(); i++)
	{
		cout << courseName[i] << ", ";
	}
	cout << endl;
}
