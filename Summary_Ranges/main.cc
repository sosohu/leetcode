#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;


class Solution {

public:

	int getLength(vector<int> &nums, int &pos){
		int res = 0;
		while(pos < nums.size()){
			res++;
			pos++;
			if(pos == nums.size()|| nums[pos-1] + 1 != nums[pos])
				break;
		}
		return res;
	}

	string itostr(int value){
		if(value == INT_MIN)	return "-2147483648";
		if(value < 0)	return "-" + itostr(-value);
		string res;
		while(value > 9){
			res.push_back(value%10 + '0');
			value = value/10;
		}
		res.push_back(value + '0');
		reverse(res.begin(), res.end());
		return res;
	}

	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		int pos = 0, len = 0;
		while(len = getLength(nums, pos)){
			if(len == 1)
				res.push_back(itostr(nums[pos - len]));
			else
				res.push_back(itostr(nums[pos - len]) + "->" + itostr(nums[pos - 1]));
		}
		return res;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{-1};
	vector<string> result = sl.summaryRanges(nums);
	for(auto ele : result)
		cout<<ele<<endl;
	return 0;

}
