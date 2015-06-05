#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;


class Solution {

public:

	bool isNear(long long a, long long b, long long t){
		if(a < b)	return isNear(b, a, t);
		return a - b <= t;
	}

	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if(k <= 0 || nums.size() == 0)	return false;
		set<int> table;
		for(int i = 0; i < nums.size(); i++){
			if(!table.empty()){
				auto low = table.lower_bound(nums[i]);
				auto up = table.upper_bound(nums[i]);
				if(*low != nums[i] && low != table.begin())	low--;
				if(low != table.end() && isNear(nums[i], *low, t))	return true;
				if(up != table.end() && isNear(nums[i], *up, t))	return true;
			}
			if(i >= k)	table.erase(nums[i-k]);
			table.insert(nums[i]);
		}
		return false;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{-1, 2147483647};
	cout<<sl.containsNearbyAlmostDuplicate(nums,1,2147483647)<<endl;

	return 0;

}
