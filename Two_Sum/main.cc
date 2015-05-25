#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {

public:

	vector<int> twoSum_1st(vector<int> &numbers, int target) {
		unordered_map<int, int>	table;
		int size = numbers.size();
		vector<int> pos(2, 0);
		
		for(int i = 0; i < size; i++){
			table[numbers[i]] = i + 1;
		}

		for(int i = 0; i < size; i++){
			if(table.count(target - numbers[i]) == 1 && table[target - numbers[i]] != i + 1){
				pos[0] = i + 1;
				pos[1] = table[target - numbers[i]];
				return pos;
			}
		}
		return pos;
    }

	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int> table;
		for(int i = 0; i < numbers.size(); i++)
			table[numbers[i]] = i + 1;
		for(int i = 0; i < numbers.size(); i++){
			if(table.count(target - numbers[i]) && table[target - numbers[i]] != i + 1)
				return vector<int>{i+1, table[target - numbers[i]]};
		}
		return vector<int>{0, 0};
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> num{3, 2, 4};

	vector<int> ret = sl.twoSum(num, 6);
	
	cout<<"Result  :("<<ret[0]<<" "<<ret[1]<<")"<<endl;

	return 0;

}
