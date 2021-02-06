#pragma once

#include <vector>
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

struct Student_info {			 //����ü
	string name;
	double midterm, finalterm;
	vector<double> homework;
};


istream& read(istream& is, Student_info& s);// ����ü ������ �Է�

istream& read_homework(istream& in, vector<double>& homework); // call by reference ���, ������ ���� ����{

bool compare(const Student_info& x, const Student_info y);

void print_students_info(int maxlen, vector<Student_info>& students);

bool space(char c);

bool not_space(char c);

vector<string> split(const string& str);