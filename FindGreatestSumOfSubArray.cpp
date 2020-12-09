#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(void) {

    vector<int> vec = {1, -2, 3, 10, -4, 7, 2, -5, 10};

    vector<int> dp(vec.size(), 0);

    dp[0] = vec[0];
    for( int i = 1; i != dp.size(); ++i) {
	if( dp[i-1] < 0) dp[i] = vec[i];
	else dp[i] = dp[i-1] + vec[i];
    }

    int res = dp[0];
    for( auto n: dp) {
	if( n > res) res = n;
    }

    cout << "Greatest sum of subarray is :" << res << endl;

    return 0;
}
