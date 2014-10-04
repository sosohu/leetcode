#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	void recursion(vector<vector<int> > &data, int n, int k){
		if(k == 1){
			vector<int> vec(1,0);
			for(int i = 1; i <= n; i++){
				vec[0] = i;
				data.push_back(vec);
			}
			return;
		}
		if(n == k){
			vector<int> vec;
			for(int i = 1; i <= n; i++)
				vec.push_back(i);
			data.push_back(vec);
			return;
		}

		vector<vector<int> > contain;
		recursion(contain, n - 1, k - 1);
		recursion(data, n - 1, k);
		for(int i = 0; i < contain.size(); i++){
			contain[i].push_back(n);
			data.push_back(contain[i]);
		}
	}

	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > data;
		if(k == 0 || n <= 0 || n < k) return data;
		if(n == k){
			vector<int> vec;
			for(int i = 1; i <= n; i++)
				vec.push_back(i);
			data.push_back(vec);
			return data;
		}
		recursion(data, n, k);
		return data;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> > ret = sl.combine(4,3);
	
	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}

	return 0;

}
