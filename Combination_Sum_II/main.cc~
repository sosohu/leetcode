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

	inline int binarysearch(vector<int> &num, int start, int end, int target){
		if(num[end] <= target)	return end;
		if(num[start] > target)	return start - 1;
		int mid = (start + end) / 2;
		if(num[mid] == target){
			int pos = mid;
			while(pos <= end && num[pos] == target)	pos++;
			return pos - 1;
		}
		if(num[mid] > target) return binarysearch(num, start, mid - 1, target);
		else	return binarysearch(num, mid+1, end, target);
	}

	vector<vector<int> > recursion(vector<int> &nums, int target, int pos){
		vector<vector<int> > data;
		vector<vector<int> > vec;
		if(pos == 0)	return data;
		if(target <= 0) return data;
		if(nums[pos-1] == target){
			data.push_back(vector<int>(1,nums[pos-1]));
		}
		if(nums[pos-1] < target && nums[pos-1] + nums[0] <= target){
			int newpos = binarysearch(nums, 0, pos - 2, target - nums[pos-1]);
			newpos++;
			#ifdef DEBUG
			cout<<"search "<<target - nums[pos-1]<<" from ";
			cout<<"0 to"<<pos-1<<endl;
			cout<<"newpos "<<newpos<<endl;
			cout<<nums[newpos]<<" "<<nums[pos-1]<<endl;
			#endif
			vec = recursion(nums, target - nums[pos-1], newpos);
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
	data[0] = 2;
	data[1] = 2;
	data[2] = 2;
	data[3] = 2;
	data[4] = 2;
	data[5] = 2;
	data[6] = 2;
	vector<vector<int> > ret = sl.combinationSum2(data, 10);

	cout<<"Result: "<<endl;
	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}

	return 0;

}
