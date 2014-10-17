#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {

	class mysort{
	public:
		bool operator()(int i, int j){
			return i < j;
		}
	} mysort;

public:

	vector<vector<int> > recursion(vector<int> &nums, int target, int pos){
		vector<vector<int> > data;
		vector<vector<int> > vec;
		if(pos == 0)	return data;
		if(target <= 0) return data;
		if(nums[pos-1] == target){
			data.push_back(vector<int>(1,nums[pos-1]));
		}
		#ifdef DEBUG
		cout<<pos<<" "<<target<<endl;
		#endif
		if(nums[pos-1] < target){
			vec = recursion(nums, target - nums[pos-1], pos-1);
			for(int i = 0; i < vec.size(); i++){
				vec[i].push_back(nums[pos - 1]);
				data.push_back(vec[i]);
			}
		}
		vec = recursion(nums, target, pos - 1);
		for(int i = 0; i < vec.size(); i++){
			data.push_back(vec[i]);
		}
		return data;
	}

	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		sort(num.begin(), num.end(), mysort);
		return recursion(num, target, num.size());
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> data(7);
	data[0] = 10;
	data[1] = 1;
	data[2] = 2;
	data[3] = 7;
	data[4] = 6;
	data[5] = 1;
	data[6] = 5;
	vector<vector<int> > ret = sl.combinationSum2(data, 8);

	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}

	return 0;

}
