#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution {

public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		if(n == 0)	return 0;
		vector<int> dp(n, 0), sum(n, 0);
		dp[0] = nums[0] < s? 0 : 1;
		sum[0] = nums[0];
		if(dp[0])	return 1;
		int result = INT_MAX;
		for(int i = 1; i < n; i++){
			if(nums[i] >= s){
				dp[i] = 1;
				sum[i] = nums[i];
			}else{
				int index = dp[i-1] == 0? 0 : i - dp[i-1];
				int total = sum[i-1];
				for(; index < i; index++){
					if(total + nums[i] < s)	break;
					total -= nums[index];
				}
				dp[i] = index == 0? 0 : i - index + 2;
				sum[i] = index == 0? total + nums[i] : total + nums[i] + nums[index-1];
			}
			if(dp[i] && result > dp[i])	result = dp[i];
		}
		return result == INT_MAX? 0 : result;
	}

	// find the last one le than the target
	int binary_search(vector<int> &sum, int begin, int end, int target){
		if(begin > end)		return begin - 1;
		if(begin == end)	return target >= sum[begin]? begin : begin - 1;
		int mid = (begin + end) / 2;
		if(sum[mid] <= target)	return binary_search(sum, mid+1, end, target);
		else	return binary_search(sum, begin, mid-1, target);
	}

	int minSubArrayLen_2nd(int s, vector<int>& nums) {
		if(nums.size() == 0)	return 0;
		if(nums.size() == 1 || nums[0] >= s)	
			return nums[0] >= s? 1 : 0;
		int res = INT_MAX, off = 0, start = 0;
		vector<int>	sum(nums.size(), nums[0]);
		for(int i = 1; i < nums.size(); i++){
			sum[i] = sum[i-1] + nums[i];
			if(sum[i] >= s){
				int pos = binary_search(sum, 0, i, sum[i] - s);
				res = min(res, i - pos);
			}
		}
		return res == INT_MAX? 0 : res;
	}
};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{10,2,3};
	
	cout<<sl.minSubArrayLen_2nd(6, nums)<<endl;

	return 0;

}
