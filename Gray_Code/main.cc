#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


class Solution {

public:

	vector<int> grayCode_1st(int n) {
		vector<int> data;
		vector<int> last;
		if(n == 0){
			data.push_back(0);
			return data;
		}

		data.push_back(0);
		data.push_back(1);

		for(int i = 2; i <= n; i++){
			last = data;
			data.clear();
			for(int j = 0; j < last.size(); j++){
				data.push_back(last[j]);
			}
			for(int j = last.size() - 1; j >= 0; j--){
				data.push_back(last[j] + pow(2, i-1));
			}
		}
		return data;
    }

	void backtrack(vector<int> &result, int &track, int pos, int n){
		if(n <= 0 || n > 31)	return;
		if(pos == n){
			result.push_back(track);
			return;
		}
		backtrack(result, track, pos+1, n);
		track |= (0x1 << pos);
		backtrack(result, track, pos+1, n);
		track ^= (0x1 << pos);
	}

	/*题目理解不对,错误答案*/
	vector<int> grayCode_DFS(int n) {
		vector<int> result;
		int track = 0;
		backtrack(result, track, 0, n);
		return result;
	}

	vector<int> grayCode(int n) {
		vector<int> result;
		if(n < 0 || n > 31)	return result;
		if(n == 0) return vector<int>(1, 0);
		vector<int> last{0, 1};
		result = last;
		for(int i = 1; i < n; i++){
			last = result;
			reverse(last.begin(), last.end());
			for(int j = 0; j < last.size(); j++){
				last[j] |= (0x1 << i);
				result.push_back(last[j]);
			}
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
    vector<int> ret = sl.grayCode(4);
	
	for(int i = 0; i < ret.size(); i++)
		cout<<ret[i]<<endl;

	return 0;

}
