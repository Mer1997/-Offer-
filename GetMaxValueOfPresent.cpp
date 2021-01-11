#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    vector< vector<int>> vec = {
	{1, 10, 3, 8},
	{12, 2, 9, 6},
	{5, 7, 4, 11},
	{3, 7, 16, 5}
    };

    vector< vector<int>> dp(vec.size(), vector<int>(vec[0].size(), 0));

    for( int i = 0; i != vec.size(); ++i) {
	for( int j = 0; j != vec[i].size(); ++j) {
	    dp[i][j] = vec[i][j];
	    if( i-1 >=0 && j-1 >= 0) {
		dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
	    }else if( i-1 >= 0 ) {
		dp[i][j] += dp[i-1][j];
	    }else if( j-1 >= 0 ) {
		dp[i][j] += dp[i][j-1];
	    }
	}
    }


    cout << "The max value of presents is " << dp.back().back() << endl;
    return 0;
}
