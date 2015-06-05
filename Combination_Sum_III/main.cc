#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

	void backtrack(vector<vector<int> > &result, vector<int> &trace,
					int k, int n, int pos){
		if(k == 0 && n == 0) {	result.push_back(trace); return; }
		if(k == 0 || n < 0 || pos > 9)	return;
		trace.push_back(pos);
		backtrack(result, trace, k-1, n-pos, pos+1);
		trace.pop_back();
		backtrack(result, trace, k, n, pos+1);
	}

	vector<vector<int> > combinationSum3(int k, int n) {
		vector<vector<int> > result;
		vector<int> trace;
		backtrack(result, trace, k, n, 1);
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> > result = sl.combinationSum3(3, 9);
	for(auto line : result){
		for(auto ele : line)
			cout<<ele<<" ";
		cout<<endl;
	}
	return 0;

}
