#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Student_info {			 //구조체
	string name;
	double midterm, finalterm;
	vector<double> homework;
};


istream& read(istream& is, Student_info& s);// 구조체 변수에 입력
istream& read_homework(istream& in, vector<double>& homework); // call by reference 사용, 벡터의 값을 변경{
bool compare(const Student_info& x, const Student_info y);

