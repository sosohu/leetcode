#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	void recursion(vector<string> &data, int n, int left, int right){
		if(left == n){
			while(right < n){
				for(int i = 0; i < data.size(); i++)
					data[i] += ")";
				right++;
			}
			return;
		}
		vector<string> left_data, right_data;
		for(int i = 0; i < data.size(); i++){
			data[i] += "(";
		}
		left_data = data;
		recursion(left_data, n, left+1, right);
		if(left > right){
			for(int i = 0; i < data.size(); i++){
				data[i][data[i].length()-1] = ')';
			}
			right_data = data;
			recursion(right_data, n, left, right+1);
		}
		data = left_data;
		data.insert(data.end(), right_data.begin(), right_data.end());
	}

	vector<string> generateParenthesis(int n) {
		if(n == 1){
			return vector<string>(1, "()");
		}
		vector<string> data(1, "");
		recursion(data, n, 0, 0);
		return data;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<string> ret = sl.generateParenthesis(3);
	
	for(int i = 0; i < ret.size(); i++)
		cout<<ret[i]<<endl;

	return 0;

}