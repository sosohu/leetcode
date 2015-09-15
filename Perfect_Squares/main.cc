#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


class Solution {

public:

	int numSquares(int n) {
		vector<long long> dp(n+1, INT_MAX);
		for(long long i = 1; i <= n; i++){
			for(long long j = 1; j * j <= i; j++){
				if(j * j == i)	dp[i] = 1;
				else	dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
		return dp[n];
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.numSquares(12)<<endl;

	return 0;

}
