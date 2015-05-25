#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

	void rotate(vector<int>& nums, int k) {
		if(nums.size() == 0 || (k = k % nums.size()) == 0)	
			return;
		reverse(nums.begin(), nums.end() - k);
		reverse(nums.end() - k, nums.end());
		reverse(nums.begin(), nums.end());
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{1,2,3,4,5,6,7};
	sl.rotate(nums, 3);
	for(auto ele : nums)
		cout<<ele<<endl;

	return 0;

}
