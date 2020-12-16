#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main(void) {

    string s = "abcuviwaenzklxjajf";

    int max = 0;

    int dp = 0;
    vector<int> idx_record(26, -1);

    for(int i = 0; i != s.length(); ++i) {
	int c = s[i] - 'a';
	if( idx_record[c] == -1) {
	    dp += 1;
	}else {
	    if( idx_record[c] < i - dp) {
		dp += 1;
	    }else {
		max = dp > max ? dp : max;
		dp = i - idx_record[c];
	    }
	}
	idx_record[c] = i;
    }

    cout << "The longest string's len without duplication char is " << max << endl;


    return 0;
}
