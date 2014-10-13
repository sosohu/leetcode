#include <iostream>
#include <string>
#include <cmath>
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

	void recursion(vector<int> &S, vector<vector<int> > &data, int n){
		if(n == 1){
			data.push_back(vector<int>(1, S[0]));
			data.push_back(vector<int>());
			return;
		}
		recursion(S, data, n - 1);
		int size = data.size();
		for(int i = 0; i < size; i++)
			data.push_back(data[i]);
		for(int i = size; i < 2*size; i++){
			data[i].push_back(S[n-1]);
		}
	}

	vector<vector<int> > subsets(vector<int> &S) {
		int n = S.size();
		vector<vector<int> > data;
		if(n == 0)	return data;
		sort(S.begin(), S.end(), mysort);
		recursion(S, data, n);
		return data;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> S(3,0);
	S[0] = 0;
	S[1] = 1;
	S[2] = 2;
    vector<vector<int> > ret = sl.subsets(S);
	
	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}	

	return 0;

}
