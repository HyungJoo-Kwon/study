#include "median.h"
#include "grade.h"
double median(vector<double> vec) {

	// ���Ľ� ������ ���� ���� Ȯ��

	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size == 0) {
		throw domain_error("���� �����Ͱ� �����ϴ�.");
	} // ����ó��

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	double output = size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];

	return output;
}
