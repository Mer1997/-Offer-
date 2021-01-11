#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool my_less(const int &lv, const int &rv) {

    string ls = to_string(lv);
    string rs = to_string(rv);
    int lcur = 0;
    int rcur = 0;

    while(lcur < ls.length() && rcur < rs.length()) {
	if( ls[lcur] < rs[rcur] ) {
	    return true;
	}else if ( ls[lcur] > rs[rcur] ) {
	    return false;
	}
	++lcur;
	++rcur;
    }

    if( lcur == ls.length() ) return true;
    else return false;
}

int main(void) {

    //vector<int> vec = {3, 2, 1, 23, 54, 9};
    vector<int> vec = {3, 32, 321};

    sort(vec.begin(), vec.end(), my_less);

    cout << "the minium permutation of vector is "; 
    for( auto n: vec) {
	cout << n;
    }
    cout << endl;

    return 0;
}
