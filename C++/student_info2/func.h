#pragma once
#include "student_info.h"
#include <numeric>

using namespace std;

bool did_all_hw(const Student_info& s);

void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&), const vector<Student_info>& did, const vector<Student_info>& didnt);

double median_analysis(const vector<Student_info>& students);

double grade_aux(const Student_info& s);

double average(const vector<double>& v);

double average_grade(const Student_info& s);

double average_analysis(const vector<Student_info>& students);

double optimistic_median(const Student_info& s);

double optimistic_median_analysis(const vector<Student_info>& students);

bool compare(const Student_info& x, const Student_info& y);
