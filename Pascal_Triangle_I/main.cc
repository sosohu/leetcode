#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	vector<vector<int> > generate_1st(int numRows) {
		vector<int> vec;
		vector<vector<int> > data;
		
		if(numRows <= 0)
			return data;

		vec.push_back(1);
		data.push_back(vec);

		for(int i = 1; i < numRows; i++){
			vector<int> tmp;
			tmp.push_back(1);
			for(int j = 1; j < i; j++){
				tmp.push_back(data[i-1][j-1] + data[i-1][j]);
			}
			tmp.push_back(1);
			data.push_back(tmp);
		}
		return data;
    }

	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > result;
		if(numRows == 0)	return result;
		result.push_back(vector<int>{1});
		for(int i = 1; i < numRows; i++){
			vector<int> cur;
			cur.push_back(1);
			for(int j = 0; j < result[i-1].size() - 1; j++)
				cur.push_back(result[i-1][j] + result[i-1][j+1]);
			cur.push_back(1);
			result.push_back(cur);
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> > ret = sl.generate(5);
	
	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}	

	return 0;

}
