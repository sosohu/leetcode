#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {

public:

	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int>	table;
		for(int i = 0; i < nums.size(); i++){
			if(table.count(nums[i]))
				if(i - table[nums[i]] <= k)
					return true;
			table[nums[i]] = i;
		}
		return false;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{1,23,4,23,2,3,4};
	cout<<sl.containsNearbyDuplicate(nums, 2)<<endl;

	return 0;

}
