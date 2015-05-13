#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		if (k > n/2){ // simple case, very important
	     	int ans = 0;
			for (int i=1; i<n; ++i){
				ans += max(prices[i] - prices[i-1],0);
			}
			return ans;
		}
		k = min(k, n/2);
		if(n <= 1)	return 0;
		vector<int> dp(n, 0), r(n, 0), left(n,0);
		for(int i = 1; i < n; i++){
			if(prices[i] >= prices[i-1]){
				left[i] = left[i-1];
			}
			else{
				left[i] = i;
			}
		}
		for(int p = 1; p <= k; p++){
			for(int i = 1; i < n; i++){
				int j = left[i];
				if(j == 0)	dp[i] = prices[i] - prices[0];
				else
					dp[i] = max(prices[i] - prices[j-1] + dp[j-1],
							prices[i] - prices[j] + r[j-1]);
			}
			
			for(int i = 1; i < n; i++)
				r[i] = max(r[i-1], dp[i]);
		}
		return r[n-1];
    }
};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> prices{1,2,4,2,8,1,7,5,9};
	cout<<sl.maxProfit(3, prices)<<endl;

	return 0;

}
