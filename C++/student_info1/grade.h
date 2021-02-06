#pragma once
#ifndef grade_h
#define grade_h

#include <vector>
#include <algorithm>
#include <stdexcept>
#include "student_info.h"

using namespace std;

double grade(const Student_info& s);

double grade(double midterm, double finalterm, double homework);

double grade(double midterm, double finalterm, const vector<double>& hw);

bool fgrade(const Student_info& s);

#endif

