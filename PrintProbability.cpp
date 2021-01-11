#include <iostream>
#include <vector>
using namespace std;

static int g_max = 6;

int main(void) {

    int num = 6;

    vector< vector<int>> dp( num, vector<int>(g_max * num + 1, 0) );

    for(int i = 1; i <= g_max; ++i) {
	dp[0][i] = 1;
    }

    for(int i = 1; i < num; ++i) {
	for(int j = 1; j <= g_max*num; ++j) {
	    for(int k = 1; k <= g_max; ++k) {
		if( dp[i-1][j] && j+k <= g_max*num) {
		    dp[i][j+k] = 1;
		}
	    }
	}
    }

    for( int i = 0; i != g_max*num+1; ++i) {
	cout << " " << dp[5][i] << " ";
    }
    cout << endl;

    return 0;
}
