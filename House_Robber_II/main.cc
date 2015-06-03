#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

	int rob_one(vector<int> &nums, int begin, int end){
		if(begin > end)		return 0;
		if(begin == end)	return nums[begin];
		if(begin + 1 == end)	return max(nums[begin], nums[end]);
		int dp1 = nums[begin], dp2 = nums[begin+1], dp3 = nums[begin+2] + dp1, cur;
		for(int i = begin + 3; i <= end; i++){
			cur = dp1 > dp2? dp1 + nums[i] : dp2 + nums[i];
			dp1 = dp2;
			dp2 = dp3;
			dp3 = cur;
		}
		return dp2 > dp3? dp2 : dp3;
	}

	int rob(vector<int>& nums) {
		int n = nums.size();
		if(nums.size() == 0)	return 0;
		if(nums.size() < 3)	return *max_element(nums.begin(), nums.end());
		int result = 0;
		//contain nums[0]
		result = nums[0] + rob_one(nums, 2, nums.size() - 2);
		// not contain nums[0]
		return max(result, rob_one(nums, 1, nums.size() - 1));
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{1,1,1};
	cout<<sl.rob(nums)<<endl;

	return 0;

}
