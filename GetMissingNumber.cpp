#include <iostream>
#include <vector>

using namespace std;

int getMissingNumber(const vector<int> &vec, const int &left, const int &right) {

    if( left >= right ) return -1;

    int mid = left + (right-left)/2;

    if( vec[mid] != mid ) {
	if( mid == 0 || vec[mid-1] == mid-1 ) {
	    return mid;
	}else {
	    return getMissingNumber(vec, left, mid);
	}
    }else {
	return getMissingNumber(vec, mid+1, right);
    }

    return -1;
}

int main(void) {

    vector<int> vec = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

    int idx = getMissingNumber(vec, 0, vec.size());

    cout << "the missing number is " << idx << endl;

    return 0;
}
