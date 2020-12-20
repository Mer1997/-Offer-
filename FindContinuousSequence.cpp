#include <iostream>

using namespace std;


int main(void) {

    int target = 18;

    int small = 0;
    int big = 0;

    int cur_sum = 0;

    while( big != target ) {
	
	if( cur_sum == target && big - small > 0 ) {
	    for(int i = small; i != big; ++i) {
		cout << i << " + ";
	    }
	    cout << big << " =" << endl;
	}

	//try up
	if( target >= cur_sum + big+1 ) {
	    big++;
	    cur_sum += big;
	    continue;
	}

	int tmp = small;
	while( tmp != big) {
	    cur_sum -= tmp;
	    if( cur_sum < target ) {
		break;
	    }
	    tmp++;
	}
	small = tmp+1;
    }


    cout << "= " << target << endl;

    return 0;
}
