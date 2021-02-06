#include "student_info.h"
#include "grade.h"

istream& read(istream& is, Student_info& s) // 구조체 변수에 입력
{	
	{
		//cout << "이름, 중간, 기말 입력 : (입력할 거 없을시 eof입력)";
		is >> s.name >> s.midterm >> s.finalterm;
		read_homework(is, s.homework);
		//cout << endl;
		
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
			//if (x == EOF)
			homework.push_back(x);
			if(homework.size() == 5)
				break;
		}
		in.clear();
	}
	return in;
}

bool compare(const Student_info& x, const Student_info y) {
	return x.name < y.name;
}

void print_students_info(int maxlen, vector<Student_info>& students)
{
	for (vector<Student_info>::const_iterator iter = students.begin(); iter != students.end(); iter++)
	{
		cout << iter->name << string(maxlen + 1 - iter->name.size(), ' ');
		try {
			double final_grade = grade(*iter);
			streamsize prec = cout.precision();

			cout << "당신의 최종 점수는 " << final_grade << endl;

		}
		catch (domain_error e) {
			cout << e.what();
		}
		
	}
}

bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

