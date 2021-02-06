#pragma once
#include <string>
#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person();
   
    Person(string myname, int myage);
   
    void setPersonInfo(string myname, int myage);
   
    void getPersonInfo() const;

    ~Person();
   
};
