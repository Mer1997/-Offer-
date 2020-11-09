#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    int n = 10;

    vector<int> dp = {0, 1, 2, 3};

    for( int i = 4; i <= n; ++i) {
	int max = 0;
	for( int j = 1; j <= dp.size()/2; ++j) {
	    int product = dp[j] * dp[i-j];
	    if( max < product) {
		max = product;
	    }

	    if( dp.size() == i)
		dp.push_back(max);
	    else
		dp[i] = max;
	}
    }

    cout << "max length for cutting rope: " << dp[dp.size()-1] << endl;
    for(auto len: dp) {
	cout << len << " ";
    }
    cout << endl;
    return 0;
}
