#include "student_info.h"

istream& read(istream& is, Student_info& s) {	// ����ü ������ �Է�
	{
		//cout << "�̸�, �߰�, �⸻ �Է� : (�Է��� �� ������ eof�Է�)";
		is >> s.name >> s.midterm >> s.finalterm;
		read_homework(is, s.homework);
		cout << endl;

	}
	return is;
}

istream& read_homework(istream& in, vector<double>& homework) {// call by reference ���, ������ ���� ����{
	if (in) {
		//cout << "���� ���� �Է�: (�������� EOF�Է�)";
		homework.clear(); // ���� ���� ����
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