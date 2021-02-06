//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//vector<string> find_urls(const string& s);
//bool not_url_char(char c);
//string::const_iterator url_end(string::const_iterator b, string::const_iterator e);
//string::const_iterator url_beg(string::const_iterator b, string::const_iterator e);
//
//
//int main(void)
//{
//	string s; 
//	getline(cin, s);
//	vector<string> v = find_urls(s);
//	for (vector<string>::size_type i = 0; i != v.size(); i++)
//		cout << v[i] << endl;
//
//	return 0;
//}
//
//vector<string> find_urls(const string& s) 
//{
//	vector<string> ret;
//	typedef string::const_iterator iter;
//	iter b = s.begin(), e = s.end();
//	while (b != e)
//	{
//		b = url_beg(b, e);
//		if(b!=e)
//		{
//			iter after = url_end(b, e);
//			ret.push_back(string(b, after));
//			b = after;
//		}
//	}
//	return ret;
//}
//
//string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
//{
//	return find_if(b, e, not_url_char);
//}
//
//bool not_url_char(char c)
//{
//	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
//	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
//}
//
//string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
//{
//	static const string sep = "://";
//	typedef string::const_iterator iter;
//
//	iter i = b;
//	while((i = search(i, e, sep.begin(), sep.end())) != e     )     // i: 시작 , e: 끝, sep.begin(): ":", sep.end(): "/"
//		{
//			if (i != b && i + sep.size() != e)
//			{
//				iter beg = i; 
//				while (beg != b && isalpha(beg[-1]))
//					beg--;
//
//				if(beg!=i&& !not_url_char(i[sep.size()]))
//					return beg;
//			}
//			i +=sep.size();
//
//		}
//		return e;
//}



#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> find_urls(const string& s);
bool not_url_char(char c);
string::const_iterator url_end(string::const_iterator b, string::const_iterator e);
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e);

int main() {
    string s;
    // 문자열을 한 행씩 입력받아 분할
    getline(cin, s);
    cout << endl << "output : " << endl;

    vector<string> v = find_urls(s);

    // 벡터 v에 저장한 단어를 각각 출력
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        cout << v[i] << endl;

    return 0;
}   

vector<string> find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();
    // look through the entire input
    while (b != e) {
        // look for one or more letters followed by ://
        b = url_beg(b, e);
        // if we found it
        if (b != e) {
            // get the rest of the URL
            iter after = url_end(b, e);
            // remember the URL
            ret.push_back(string(b, after));
            // advance b and check for more URLs on this line
            b = after;
        }
    }
    return ret;
}



string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}

bool not_url_char(char c)
{
    // characters, in addition to alphanumerics, that can appear in a URL
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    // see whether c can appear in a URL and return the negative
    return !(isalnum(c) ||
        find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";
    typedef string::const_iterator iter;
    // i marks where the separator was found
    iter i = b;
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        // make sure the separator isn't at the beginning or end of the line
        if (i != b && i + sep.size() != e) {
            // beg marks the beginning of the protocol-name
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;// is there at least one appropriate character before and after the separator?
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        // the separator we found wasn't part of a URL advance i past this separator
        i += sep.size();
    }
    return e;
}