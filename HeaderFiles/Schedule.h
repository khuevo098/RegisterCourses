#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Schedule
{
private:
	vector<string> courseName;
public:
	~Schedule();
	void add_to_schedule(string course_name);
	void remove_from_schedule(string course_name);
	void print_schedule();
};

