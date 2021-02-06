#include "Person.h"


Person::Person()
{
	name = "";
	age = 0;
	cout << "기본 person 생성자 호출" << endl;
}
Person::Person(string myname, int myage)
{
	name = myname;
	age = myage;
}
void Person::setPersonInfo(string myname, int myage)
{
	name = myname;
	age = myage;
}
void Person::getPersonInfo() const {
	cout << "이름 : " << name << endl;
	cout << "나이 : " << age << endl;
}
Person::~Person()
{
	cout << "소멸자 (destructor) 호출 " << endl;
}
