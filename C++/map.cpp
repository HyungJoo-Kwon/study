#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	map<string, int> m;
	
	m.begin(); // 반복자 시작
	m.end(); // 반복자 끝

	m.insert(make_pair("a", 1));  //키 값 삽입
	m["b"] = 2; // b키에 값 2 입력
	m.insert(make_pair("c", 3));

	m.erase("a"); 
	m.erase(m.find("b"));
	// erase(key)

	cout << "c: " << m.find("c")->second << endl;	//  3
	cout << "c: " << m.count("c") << endl;			//  1
	for (map<string, int>::const_iterator it = m.begin(); it != m.end(); it++) // 	for (auto it = m.begin(); it != m.end(); it++) // 
	{
		cout << "key : " << it->first << endl;		//  
		cout << "value : " << it->second << endl;	//
	}

	// find(key);


	// m.clear();


	return 0;
}