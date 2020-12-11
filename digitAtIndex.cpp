#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int countOfIntegers(int digits) {
    if( digits == 1) return 10;
    int count = (int)pow(10, digits-1);
    return 9*count;
}

int beginNumber(int digits) {
    if( digits == 1) {
	return 0;
    }
    return (int)pow(10, digits-1);
}

int digitAtIndex( int num, int digits) {
    int number = beginNumber(digits) + num / digits;
    int index_right = digits - num % digits;
    for( int i = 1; i < index_right; ++i) {
	number /= 10;
    }
    return number %10;
}

int getDigitAtIndex( int num) {

    if( num < 0) return -1;

    int digits = 1;
    while(true) {
	int tmp = countOfIntegers(digits);
	if( num < tmp * digits) {
	    return digitAtIndex(num, digits);
	}else {
	    num -= tmp * digits;
	}
	++digits;
    }

    return -1;
}


int main(void) {

    int num = 10;

    int ans = getDigitAtIndex(num);

    cout << "the digit at index[" << num << "] is " << ans << endl;
    return 0;
}
