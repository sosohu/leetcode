#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

	class mysort{
		public:
			bool operator()(int i, int j){
				return i < j;
			}
	} mysort;

public:

	vector<vector<int> > permute_1st(vector<int> &num) {
		int len = num.size();	
		vector<vector<int> > data;
		if(len == 0)	return data;

		sort(num.begin(), num.end(), mysort);
		data.push_back(vector<int>(1, num[0]));
		int size;
		bool same = false;
		vector<int> vec;
		vector<vector<int> > tmp;
		vector<int>::iterator iter;
		for(int i = 1; i < len; i++){
			size = data.size();
			tmp = data;
			data.clear();
			for(int j = 0; j < size; j++){
				same = false;
				for(int k = 0; k < tmp[j].size() + 1; k++){
					if(!same){
						vec = tmp[j];
						iter = vec.begin();
						for(int p = 0; p < k; p++)
							iter++;
						vec.insert(iter, num[i]);
						data.push_back(vec);
					}
					if(k != tmp[j].size()){
						if(num[i] == tmp[j][k])
							same = true;
						else
							same = false;	
					}
				}
			}
		}
		return data;
    }

	vector<vector<int> > permute(vector<int> &num) {
		vector<int> data(num);
		sort(data.begin(), data.end());
		vector<vector<int> > result;
		while(1){
			int peak = data.size() - 1;
			while(peak > 0 && data[peak] <= data[peak-1])	peak--;
			result.push_back(data);
			if(peak == 0)	break;
			int before_peak = peak - 1;
			vector<int>::iterator next_peak = lower_bound(data.begin() + peak, data.end(), 
										data[before_peak], greater<int>());
			next_peak--;
			swap(data[before_peak], *next_peak);
			reverse(data.begin() + peak, data.end());
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> data(5, 0);
	data[0] = 1;
	data[1] = 2;
	data[2] = 1;
	data[3] = 4;
	data[4] = 1;
    vector<vector<int> > ret = sl.permute(data);
	
	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<endl;
		cout<<endl;
	}
	cout<<ret.size()<<endl;

	return 0;

}
