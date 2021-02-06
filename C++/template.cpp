#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

template<class T>
T median(vector<T> v)
{
	//typedef typename auto vec_sz;
	typedef typename vector<T>::size_type vec_sz;

	vec_sz size = v.size();

	if (size == 0)
		throw domain_errer;

	sort(v.begin(), v.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}


int main(void)
{
	vector<double> med;
	while (getline(cin,s)
	{
		med.push_back(cin);
	}

	return 0;
}