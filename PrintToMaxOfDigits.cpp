#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printDigits(int n, string s) {

    if( n == 0) {
	cout << s << endl;
	return;
    }else {
	for(int i = 0; i != 10; ++i) {
	    if( i != 0 || s != "")
		printDigits(n-1, s+(char)('0'+i));
	    else
		printDigits(n-1, s);
	}
    }
}

int main(void) {

    printDigits(3, "");
    return 0;
}
