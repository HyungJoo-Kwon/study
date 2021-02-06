#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Student_info {			 //����ü
	string name;
	double midterm, finalterm;
	vector<double> homework;
};


istream& read(istream& is, Student_info& s);// ����ü ������ �Է�
istream& read_homework(istream& in, vector<double>& homework); // call by reference ���, ������ ���� ����{
bool compare(const Student_info& x, const Student_info y);

