#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


class Solution {

public:

	vector<int> grayCode(int n) {
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

};

int main(int argc, char** argv)
{
	Solution sl;
    vector<int> ret = sl.grayCode(4);
	
	for(int i = 0; i < ret.size(); i++)
		cout<<ret[i]<<endl;

	return 0;

}
