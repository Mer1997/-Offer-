#include <iostream>
#include <vector>

using namespace std;


int main(void) {

    string number = "12258";

    vector<long long> dp(number.length()+1, 0);

    dp[0] = 1;
    for(int i = 1; i != number.length(); ++i) {

	dp[i] += dp[i-1];
	if( number[i-1] == '1' || (number[i-1] == '2' && number[i] < '7') ) {
	    if(i-2>-1) dp[i] += dp[i-2];
	    else dp[i] += 1;
	}
    }

    cout << "The Count of Translatation is " << dp[number.length()-1] << endl;

    return 0;
}
