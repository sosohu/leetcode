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

	vector<vector<int> > recursion(vector<int> &nums, vector<int> count, int target, int pos){
		vector<vector<int> > data;
		vector<vector<int> > vec;
		if(pos == 0)	return data;
		if(target <= 0) return data;
		if(nums[pos-1] == target){
			data.push_back(vector<int>(1,nums[pos-1]));
		}
		if(nums[pos-1] < target && nums[pos-1] + nums[0] <= target){
			int  newpos;
			if(count[pos-1] == 1){
				if(pos - 1 == 0)
					return data;
				newpos = binarysearch(nums, 0, pos - 2, target - nums[pos-1]);
			}
			else{
				newpos = binarysearch(nums, 0, pos - 1, target - nums[pos-1]);
				if(newpos == pos - 1)
					count[pos-1]--;
			}
			newpos++;
			vec = recursion(nums, count, target - nums[pos-1], newpos);
			for(int i = 0; i < vec.size(); i++){
				vec[i].push_back(nums[pos - 1]);
				data.push_back(vec[i]);
			}
		}
		vec = recursion(nums, count, target, pos - 1);
		for(int i = 0; i < vec.size(); i++){
			data.push_back(vec[i]);
		}
		return data;
	}

	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		if(num.size() == 0){
			vector<vector<int> > data;
			return data;
		}
		sort(num.begin(), num.end(), mysort);
		vector<int> count;
		vector<int> number;
		int pos = 0, i = 0;
		count.push_back(1);
		number.push_back(num[0]);
		for(i = 1; i < num.size(); i++){
			if(num[i] != number[pos]){
				number.push_back(num[i]);
				count.push_back(1);
				pos++;
			}else{
				count[pos]++;
			}
		}
		return recursion(number, count, target, number.size());
    }


};

int main(int argc, char** argv)
{
	Solution sl;
	int array[] = {10,1,2,7,6,1,5};
	vector<int> data;
	//vector<int> data(7, 0);
	/*
	for(int i = 0; i < 7; i++)
		data[i] = array[i];
	*/
	vector<vector<int> > ret = sl.combinationSum2(data, 8);

	cout<<"Result: "<<endl;
	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}

	return 0;

}
