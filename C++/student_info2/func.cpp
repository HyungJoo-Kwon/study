#include "func.h"
#include "median.h"
#include "grade.h"

bool did_all_hw(const Student_info& s)
{
	return (find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end();
}

void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&), const vector<Student_info>& did, const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << endl;
}

double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);

	return median(grades);
}

double grade_aux(const Student_info& s)
{
	try
	{
		return grade(s);
	}
	catch (domain_error)
	{
		return grade(s.midterm, s.finalterm, 0);
	}
}

double average(const vector<double>& v)
{
	return accumulate(v.begin(), v.end(), 0.0 / v.size());
}

double average_grade(const Student_info& s)
{
	return grade(s.midterm, s.finalterm, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), average_grade);

	return median(grades);
}

double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

	if (nonzero.empty())
		return grade(s.midterm, s.finalterm, 0);
	else
		return grade(s.midterm, s.finalterm, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);

	return median(grades);
}
