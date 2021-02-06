#include "Person.h"

int main()
{
    int* pt = new int(5);  // 정수형 변수 안에 4를 집어넣음..
    cout << *pt << endl; // 5
    delete pt;


    //Person pArr[3];
    Person* pArr[3];
    string name_str;
    int age;
    for (int i = 0; i < 3; i++)
    {
        cout << "이름: ";
        cin >> name_str;
        cout << "나이: ";
        cin >> age;
        //pArr[i].setPersonInfo(name_str, age);
        pArr[i] = new Person(name_str, age);   // pArr[i] 는 주소.
    }
    for (int i = 0; i < 3; i++)
    {
        //pArr[i].getPersonInfo();
        pArr[i]->getPersonInfo(); // (*pArr[i]).getPersonInfo();
        delete pArr[i];
    }

    

    return 0;
}