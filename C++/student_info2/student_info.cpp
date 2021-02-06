#include "student_info.h"

istream& read(istream& is, Student_info& s) {	// 구조체 변수에 입력
	{
		//cout << "이름, 중간, 기말 입력 : (입력할 거 없을시 eof입력)";
		is >> s.name >> s.midterm >> s.finalterm;
		read_homework(is, s.homework);
		cout << endl;

	}
	return is;
}

istream& read_homework(istream& in, vector<double>& homework) {// call by reference 사용, 벡터의 값을 변경{
	if (in) {
		//cout << "과제 점수 입력: (마지막에 EOF입력)";
		homework.clear(); // 이전 내용 삭제
		double x;
		while (in >> x)
		{
			if (x == EOF)
				break;
			homework.push_back(x);
		}
		in.clear();
	}
	return in;
}

bool compare(const Student_info& x, const Student_info y) {
	return x.name < y.name;
}