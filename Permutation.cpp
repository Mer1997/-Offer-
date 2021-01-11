#include <iostream>
#include <string>
#include <vector>


using namespace std;

void permutation(const string &s, string buf, const int &index) {

    if( buf.length()+s.length() == index) {
	cout << buf << endl;
    }

    for(int i = 0; i != s.length(); ++i) {
	buf += s[i];
	permutation(s.substr(0, i) + s.substr(i+1), buf, index+1);
	buf = buf.substr(0, buf.length()-1);
    }

    return;

}   

int main(void) {

    string s = "abc";
    permutation(s, "", 0);

    return 0;
}
