#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {

public:

	vector<vector<int> > recursion(vector<int> &num, unordered_map<int, vector<pair<int, int> > > &table, int target, int pos, int size){
		vector<vector<int> > data;
		if(pos == size - 4){
			if(num[pos] + num[pos+1] + num[pos+2] + num[pos+3] == target){
				vector<int> vec(num.begin() + pos, num.end());
				data.push_back(vec);
			}
			return data;
		}
		int left = target - num[pos];
		int half;
		vector<int> vec(4,0);
		vec[0] = num[pos];
		for(int i = pos + 1; i < size; i++){
			if(num[i] == num[i-1])	continue;
			half = left - num[i];
			if(table.count(half) == 1){
				vec[1] = num[i];
				for(int j = 0; j < table[half].size(); j++){
					if(table[half][j].first > i && table[half][j].second > i){
						vec[2] = num[table[half][j].first];
						vec[3] = num[table[half][j].second];
						data.push_back(vec);
					}
				}
			}
		}
		vector<vector<int> > sub_data = recursion(num, table, target, pos+1, size);
		data.insert(data.end(), sub_data.begin(), sub_data.end());
		return data;
	}

	vector<vector<int> > fourSum(vector<int> &num, int target) {
		int size = num.size();
		if(size <= 3){
		    vector<vector<int> > data;
		    return data;
		}
		sort(num.begin(), num.end());
		unordered_map<int, vector<pair<int, int> > > table;
		for(int i = 0; i < size; i++){
			for(int j = i + 1; j < size; j++){
				table[num[i] + num[j]].push_back(pair<int, int>(i, j));
			}
		}
		return recursion(num, table, target, 0, size);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {-3, -2, -1, 0, 0, 1, 2, 3};
	vector<int> data;
	for(int i = 0; i < 8; i++)
		data.push_back(A[i]);
	vector<vector<int> > ret = sl.fourSum(data, 0);
	
	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++){
			cout<<ret[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;

}
