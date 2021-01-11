#include <iostream>
#include <vector>

using namespace std;


int main(void) {

    vector<int> vec = {1, 2, 2, 3, 2, 5, 18, 2, 2, 7, 12, 3, 1, 6, 2, 3, 5, 2, 2, 2, 2, 2, 2, 3, 5, 6, 1, 2, 2, 2};

    int tmp;
    int cnt = 0;
    for( auto n: vec) {
	if( cnt == 0) {
	    tmp = n;
	    cnt = 1;
	}else if( tmp == n) {
	    cnt++;
	}else {
	    cnt--;
	}
    }

    cout << "The number that more than half in vec is: " << tmp << endl;  

    return 0;
}
