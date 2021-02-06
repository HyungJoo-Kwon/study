#include "median.h"
#include "grade.h"
double median(vector<double> vec) {

	// 정렬시 점수의 존재 유무 확인

	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size == 0) {
		throw domain_error("과제 데이터가 없습니다.");
	} // 예외처리

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	double output = size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];

	return output;
}
