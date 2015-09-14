#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

	int missingNumber(vector<int>& nums) {	
		for(int i = 0; i < nums.size();){
			if(i != nums[i] && nums[i] != nums.size()){
				swap(nums[i], nums[nums[i]]);
			}else{
				i++;
			}
		}
		for(int i  = 0; i < nums.size(); i++)
			if(i != nums[i])	return i;
		return nums.size();
    }
};

int main(int argc, char** argv)
{
	Solution sl;

	return 0;

}
