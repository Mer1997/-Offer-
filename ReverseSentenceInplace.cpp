#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void m_reverse(string &s, const int &left, const int &right) {

    //reverse(s.begin()+left, s.begin()+right);

    cout << left  << " : " << right << endl;

    int tmp = left;
    while( tmp - left < (right - left)/2 ) {

	char c = s[tmp];
	s[tmp] = s[right-1-tmp+left];
	s[right-1-tmp+left] = c;

	tmp++;
    }
}

int main(void) {

    string s = "I am a  student.";

    int left = 0;
    int right= s.length();

    m_reverse(s, left, right);

    int idx = 0;
    while( left != s.length() ) {

	if( idx == s.length() || s[idx] == ' ' ) {
	    right = idx;
	    if( s[left] != ' ' ) {
		m_reverse(s, left, right);
	    }
	    left = idx;
	    idx++;
	    continue;
	}

	if( s[left] == ' ') {
	    left = idx;
	}else {
	    right = idx;
	}

	++idx;
    }

    cout << s << endl;

    return 0;
}
