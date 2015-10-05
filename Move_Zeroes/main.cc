#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int pos = 0, last = 0;
		while(pos < nums.size()){
			if(nums[pos]){
				if(pos != last){
					nums[last] = nums[pos];
					nums[pos] = 0;
				}
				last++;
			}
			pos++;
		}
	}
};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{0, 1, 0, 3, 12};
	sl.moveZeroes(nums);
	for(auto ele : nums)
		cout<<ele<<endl;
	return 0;
}
