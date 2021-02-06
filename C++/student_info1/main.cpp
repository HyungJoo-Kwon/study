#include <vector>
#include <iostream>
#include <chrono>
#include <iomanip> // setprecision()
#include <string>
#include <ios>	// streamsize
#include <algorithm> // sort()

using namespace std;

double grade(double midterm, double finalterm, double homework);
double grade(double midterm, double finalterm, const vector<double>& hw);
double median(vector<double> vec);

int main()
{
	
	cout << "이릅을 입력하세요: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;
	
	cout << "중간, 기말 점수를 입력 (80.0 90.0) : ";
	double midterm, finalterm;
	cin >> midterm >> finalterm;

	cout << "과제 점수 입력, "  "마지막에 EOF(end-of-file)입력 :";

	vector<double> homework;
	double x;
	while (cin >> x)
	{
		homework.push_back(x);
	}

	double median_value = median(homework);
	streamsize prec = cout.precision();
	double result = grade(midterm, finalterm, median_value);

	cout << "당신의 최종 점수는 " << endl << setprecision(4) << fixed << result << setprecision(prec) << endl;



	return 0;
}

double grade(double midterm, double finalterm, double homework)
{
	double result = 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
	return result;
}

double grade(double midterm, double finalterm, const vector<double>& hw)
{
	if (hw.size == 0)
		throw domain error("과제 데이터가 없습니다.");
	return grade(midterm, finalterm, median(hw));
}

double median(vector<double> vec) {

	// 정렬시 점수의 존재 유무 확인

	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size == 0)
	{
		throw domain error("과제 데이터가 없습니다.");
	}


	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	double output = size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];

	return output;
}
