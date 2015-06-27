#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

	int rob(vector<int>& nums) {
		int n = nums.size();
		if(n == 0)	return 0;
		if(n == 1)	return nums[0];
		int dp1 = nums[0], dp2 = max(nums[0], nums[1]);
		for(int i = 2; i < n; i++){
			int cur = max(nums[i] + dp1, dp2);
			dp1 = dp2;
			dp2 = cur;
		}
		return dp2;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{1,2,4,2,8,1,7,5,9};
	cout<<sl.rob(nums)<<endl;

	return 0;

}
