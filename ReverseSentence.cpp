#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(void) {

    string s = "I am a student.";

    regex reg("\\s+");
    sregex_token_iterator iter(s.begin(), s.end(), reg, -1);
    sregex_token_iterator end;
    vector<string> vec(iter, end);

    string ans;
    for( int i = vec.size()-1; i != -1; --i) {

	ans += vec[i];
	ans += " ";
    }
    
    cout << ans << endl;

    return 0;
}
