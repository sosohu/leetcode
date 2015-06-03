#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


class Solution {

public:

	int partition(vector<int> &nums, int begin, int end, int k){
		if(begin == end)	return nums[begin];
		int index = rand() % (end - begin + 1) + begin;
		int small = begin, bench = nums[index];
		swap(nums[end], nums[index]);
		for(int i = begin; i <= end; i++)
			if(bench > nums[i]){
				if(i != small)
					swap(nums[i], nums[small]);
				small++;
			}
		swap(nums[small], nums[end]);
		if(k == end - small + 1)
			return bench;
		if(k < end - small + 1)
			return partition(nums, small+1, end, k);
		else
			return partition(nums, begin, small-1, k - (end - small + 1));
	}

	int findKthLargest(vector<int>& nums, int k) {
		return partition(nums, 0, nums.size() - 1, k);
    }
};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{3,2,1,5,4,6};
	cout<<sl.findKthLargest(nums, 2)<<endl;

	return 0;

}
