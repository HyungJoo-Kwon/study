#include "Person.h"


Person::Person()
{
	name = "";
	age = 0;
	cout << "�⺻ person ������ ȣ��" << endl;
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
	cout << "�̸� : " << name << endl;
	cout << "���� : " << age << endl;
}
Person::~Person()
{
	cout << "�Ҹ��� (destructor) ȣ�� " << endl;
}
