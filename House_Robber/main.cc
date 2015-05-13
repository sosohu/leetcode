#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

	int rob(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n, 0);
		int result = 0;
		for(int i = 0; i < n; i++){
			dp[i] = nums[i];
			for(int j = 0; j < i - 1; j++)
				dp[i] = max(dp[j] + nums[i], dp[i]);
			result = max(result, dp[i]);
		}
		return result;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{1,2,4,2,8,1,7,5,9};
	cout<<sl.rob(nums)<<endl;

	return 0;

}
