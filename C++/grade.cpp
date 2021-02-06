#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip> // setprecision()


class Student_info 
{
public:
	Student_info();
	Student_info(std::istream&);
	std::string name() const		// 값을 안 바꿀거라 const 
	{
		return n;
	}
	bool valid() const
	{
		return !homework.empty();
	}
	std::istream& read(std::istream& in);
	double grade() const;

	char check_pass() 
	{
		auto avg = (midterm + final)/2;
		if (avg >= 60)
			return 'P';
		return 'F';
	}



private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;
	
};

Student_info::Student_info():midterm(0),final(0) {}		 // 아무 것도 없을때 
Student_info::Student_info(std::istream& is)
{
	read(is);
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw);
double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);
double Student_info::grade() const
{
	return ::grade(midterm, final, homework);  // 클래스 외부의 grade함수 호출
}
double median(std::vector<double>);
bool compare(const Student_info& x, const Student_info& y);


int main(void)
{
	std::vector<Student_info> students;
	Student_info record;
	std::string::size_type maxlen = 0;
	
	while (record.read(std::cin))
	{
		maxlen = std::max(maxlen, record.name().size());
		students.push_back(record); 
		
	}
	sort(students.begin(), students.end(), compare);
		
	for (std::vector<Student_info>::size_type i = 0; i != students.size(); i++)
	{
		std::cout << students[i].name() // changed
			<< std::string(maxlen + 1 - students[i].name().size(), ' ');

		try
		{
			double final_grade = students[i].grade();
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << final_grade << std::setprecision(prec) << students[i].check_pass() << std::endl;
		}
		catch (std::domain_error e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}

std::istream& Student_info::read(std::istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in, homework);
	return in;
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw) 
{
	if (in) 
	{
		hw.clear();
		double x;
		while (in >> x)
			hw.push_back(x);
		in.clear();
	}
	
	return in;
}
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}
double grade(double midterm, double final, const std::vector<double>& hw)
{
	if (hw.size() == 0)
		throw std::domain_error::domain_error("과제가 없습니다");
	return grade(midterm, final, median(hw));
}
double median(std::vector<double> vec)
{
	typedef std::vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size == 0)
		throw std::domain_error::domain_error("빈 벡터의 메디안 값입니다.");
	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}
bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}



