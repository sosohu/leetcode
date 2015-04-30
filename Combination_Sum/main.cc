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
			vec = recursion(nums, target - nums[pos-1], pos);
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

	vector<vector<int> > combinationSum_1st(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end(), mysort);
		return recursion(nums, target, nums.size());
    }

	void backtrack(vector<int> &num, int target, int pos, 
					vector<vector<int> > &result, vector<int> &track){
		if(target == 0){
			result.push_back(track);
			return;
		}
		if(pos == -1)	return;
		if(num[pos] <= target){
			track.push_back(num[pos]);
			backtrack(num, target - num[pos], pos, result, track);
			track.pop_back();
		}
		pos--;
		while(pos >= 0 && num[pos] == num[pos+1]) pos--;
		if(pos >= 0){
			backtrack(num, target, pos, result, track);
		}
	}

	vector<vector<int> > combinationSum(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end(), greater<int>());
		vector<vector<int> > result;
		vector<int> track;
		backtrack(nums, target, nums.size()-1, result, track);
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> data(4);
	data[0] = 2;
	data[1] = 3;
	data[2] = 6;
	data[3] = 7;
	vector<vector<int> > ret = sl.combinationSum(data, 7);

	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}

	return 0;

}
