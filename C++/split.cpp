#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(const string& s);
string::size_type width(const vector<string>& v);
vector<string> frame(const vector<string>& v);
vector<string> vcat(const vector<string>& top, const vector<string>& bottom);
vector<string> vcat2(const vector<string>& top, const vector<string>& bottom);
vector<string> vcat3(const vector<string>& top, const vector<string>& bottom);
vector<string> hcat(const vector<string>& left, const vector<string>& right);
vector<string> split2(const string& s);
bool is_palindrome(const string& s);




int main(void)
{
	string s;
	getline(cin, s);
	// getline(cin, y);

	cout << endl << "output: " << endl;
	
	vector<string> v_origin = split(s);
	//vector<string> v_add = split(y);
	//v_origin = vcat(v_origin, v_add);
	vector<string> v_output = frame(v_origin);
	v_output = vcat3(v_origin, frame(v_origin));

	for (vector<string>::size_type i = 0; i != v_output.size(); i++)
	{
		cout << v_output[i] << endl;
	}
	
	
	return 0;
}

vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size())
	{
		while (i != s.size() && isspace(s[i]))  // 문자 입력 전 공백 무시
			i++;
		string_size j = i;
		while (j != s.size() && !isspace(s[j]))
		{
			j++;
		}
		if (i != j)
		{
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}

vector<string> split2(const string& s)
{
	typedef string::const_iterator iter;
	vector<string> ret;
	iter i = s.begin();

	while (i != s.end())
	{
		i = find_if(i, s.end(), not_space);   // 
		iter j = find_if(i, s.end(), space);
	 
		if (i != s.end()) 
			ret.push_back(string(i, j - 1));
		i = j;
	}
}

bool space(char c) {
	return isspace(c);
}

bool not_space(char c) {
	return !isspace(c);
}

bool is_palindrome(const string& s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}

string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); i++)
	{
		maxlen = max(maxlen, v[i].size());
	}

	return maxlen;

}

vector<string> frame(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');

	ret.push_back(border);

	for (vector<string>::size_type i = 0; i != v.size(); i++)
	{
		ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
	}
	ret.push_back(border);
	return ret;
}

//vector<string> frame_iter(const vector<string>& v)
//{
//	vector<string>::const_iterator iter = v.begin();
//	vector<string> ret;
//	string::size_type maxlen = width(v);
//	string border(maxlen + 4, '*');
//
//	while (iter != v.end())
//	{
//		ret.push_back("* " + *iter + string(maxlen - v.end(), ' ') + " *");
//		iter++;
//	}
//
//	ret.push_back(border);
//	return ret;
//}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
	vector<string> ret = top;

	for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); it++)
	{
		ret.push_back(*it);
	}
	
	return ret;
}

vector<string> vcat2(const vector<string>& top, const vector<string>& bottom)
{
	vector<string> ret = top;

	ret.insert(ret.end(), bottom.begin(), bottom.end());

	return ret;
}

vector<string> vcat3(const vector<string>& top, const vector<string>& bottom)
{
	vector<string> ret = top;

	copy(bottom.begin(), bottom.end(), back_inserter(ret));

	return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;
	string::size_type width1 = width(left) + 1;
	vector<string>::size_type i = 0, j = 0;

	while (i != left.size() || j != right.size())
	{
		string s;
		
		if (i != left.size())
			s = left[i++];
		s += string(width1 - s.size(), ' ');
		if (j != right.size())
			s += right[j++];

		ret.push_back(s);
	}

	return ret;
}
