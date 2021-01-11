#include <iostream>

using namespace std;


int main(void) {
    
    //1111
    int n = 15;

    int count = 0;
    while( n) {
	++count;
	n &= (n-1);
    }

    cout << "the number of 1 in n is: " << count << endl;

}
