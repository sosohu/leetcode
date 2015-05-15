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

	int Merge_aux(int s, vector<int>& nums, int begin, int end){
		if(begin > end)	return 0;
		if(begin == end)	return nums[begin] >= s? 1 : 0;
		int mid = (begin + end) / 2;
		int left = Merge_aux(s, nums, begin, mid);
		int right = Merge_aux(s, nums, mid+1, end);
		int backward = mid - 1, forward = mid + 2;
		int sum = nums[mid] + nums[mid+1];
		int cur = 2;
		while(sum < s && (backward >= begin || forward <= end)){
			if(backward < begin)	sum += nums[forward++];
			else if(forward > end)	sum += nums[backward--];
			else{
				if(nums[forward] > nums[backward]) sum += nums[forward++];	
				else	sum += nums[backward--];
			}
			cur++;
		}
		if(sum < s)	return 0;
		return min(min((left == 0?INT_MAX : left), (right == 0? INT_MAX : right)), cur);
	}

	int minSubArrayLen_2nd(int s, vector<int>& nums) {
		int n = nums.size();
		return Merge_aux(s, nums, 0, n-1);
	}
};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{2,3,1,2,4,3};
	
	cout<<sl.minSubArrayLen_2nd(7, nums)<<endl;

	return 0;

}
