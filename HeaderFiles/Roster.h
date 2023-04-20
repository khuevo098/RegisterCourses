#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Roster
{
private:
	vector<string> studentName;
public:
	~Roster();
	void add_to_roster(string student_name);
	void remove_from_roster(string student_name);
	void print_roster();
};

