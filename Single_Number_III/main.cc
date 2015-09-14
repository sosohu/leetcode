#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:
	vector<int> singleNumber(vector<int>& nums) {
		if(nums.size() < 3)	return nums;
		for(int i = 0; i < 32; i++){
			vector<int> left, right;
			int mask = (0x1 << i);
			for(int i = 0; i < nums.size(); i++){
				if(nums[i] & mask){
					left.push_back(nums[i]);
				}else{
					right.push_back(nums[i]);
				}
			}
			if(left.size() % 2){
				vector<int> res;
				res.push_back(singleNumber_aux(left));
				res.push_back(singleNumber_aux(right));
				return res;
			}
		}
    }

	int singleNumber_aux(vector<int>& nums){
		int res = nums[0];
		for(int i = 1; i < nums.size(); i++)
			res = res ^ nums[i];
		return res;
	}

};

int main(int argc, char** argv)
{
	Solution sl;

	return 0;

}
