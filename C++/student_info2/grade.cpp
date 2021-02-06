#include "grade.h"
#include "median.h"

double grade(const Student_info& s) {
	return grade(s.midterm, s.finalterm, s.homework);
}

double grade(double midterm, double finalterm, double homework) {
	double result = 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
	return result;
}

double grade(double midterm, double finalterm, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("과제 데이터가 없습니다.");
	return grade(midterm, finalterm, median(hw));
}
