#include "Person.h"

int main()
{
    int* pt = new int(5);  // ������ ���� �ȿ� 4�� �������..
    cout << *pt << endl; // 5
    delete pt;


    //Person pArr[3];
    Person* pArr[3];
    string name_str;
    int age;
    for (int i = 0; i < 3; i++)
    {
        cout << "�̸�: ";
        cin >> name_str;
        cout << "����: ";
        cin >> age;
        //pArr[i].setPersonInfo(name_str, age);
        pArr[i] = new Person(name_str, age);   // pArr[i] �� �ּ�.
    }
    for (int i = 0; i < 3; i++)
    {
        //pArr[i].getPersonInfo();
        pArr[i]->getPersonInfo(); // (*pArr[i]).getPersonInfo();
        delete pArr[i];
    }

    

    return 0;
}