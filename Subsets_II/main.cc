#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

	class mysort{
	public:
		bool operator()(int i, int j){
			return i <= j;
		}
	}	mysort;

public:
	vector<vector<int> > recursion(vector<int> &S, int len){
		vector<vector<int> > data;
		if(len == 0){	
			vector<int> vec;
			data.push_back(vec);
			return data;
		}

		vector<vector<int> > tmp, local_tmp;
		int last = S[len-1];

		int i = len - 2;
		for( ;i >= 0; i--){
			if(S[i] != last)
				break;
		}
		tmp = recursion(S, i+1);
		for(int j = 0; j < tmp.size(); j++)
			data.push_back(tmp[j]);
		for(int j = 1; j <= len - 1 -i; j++ ){
			vector<int> local;
			local_tmp = tmp;
			for(int k = 0; k < j; k++){
				local.push_back(last);
			}
			for(int k = 0; k < local_tmp.size(); k++){
				local_tmp[k].insert(local_tmp[k].end(), local.begin(), local.end());
				data.push_back(local_tmp[k]);
			}
		}
		return data;		
	}
	
	vector<vector<int> > subsetsWithDup_1st(vector<int> &S) {
		vector<int> tmp = S;
		sort(tmp.begin(), tmp.end(), mysort);
		int len = S.size();
		return recursion(tmp, len);
    }

	void backtrack(vector<vector<int> > &result, vector<int> &track, vector<int> & data,
					vector<int> &count, int pos, int n){
		if(pos == n){
			result.push_back(track);
			return;
		}
		for(int i = 0; i < count[pos]; i++){
			track.push_back(data[pos]);
			backtrack(result, track, data, count, pos+1, n);
		}
		for(int i = 0; i < count[pos]; i++){
			track.pop_back();
		}
		backtrack(result, track, data, count, pos+1, n);
	}

	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());
		vector<int> data, count;
		int last = 0;
		for(int i = 1; i < S.size(); i++){
			if(S[i] != S[i-1]){
				data.push_back(S[last]);
				count.push_back(i - last);
				last = i;
			}
		}
		data.push_back(S[last]);
		count.push_back(S.size() - last);
		vector<vector<int> > result;
		vector<int> track;
		backtrack(result, track, data, count, 0, data.size());
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> data;
	for(int i = 0; i < 3; i++)
		data.push_back(i+1);
	data[2] = 2;
	
	vector<vector<int> > ret = sl.subsetsWithDup(data);

	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}

	return 0;

}
