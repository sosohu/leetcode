#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > data(n, vector<int>(n, 0));
		if(n == 0)	return data;
		int margin = 0;
		int start = 1;
		while(margin < n/2){
			for(int j = margin; j < n - margin; j++){
				data[margin][j] = start++;
			}

			for(int i = margin + 1; i < n - margin; i++){
				data[i][n - margin - 1] = start++;
			}

			for(int j = n - margin - 2; j >= margin; j--){
				data[n - margin - 1][j] = start++;
			}

			for(int i = n - margin - 2; i >= margin + 1; i--){
				data[i][margin] = start++;
			}
			margin++;
		}
		if(margin*2 < n)
			data[margin][margin] = n*n;
		return data;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> > ret = sl.generateMatrix(6);
	
	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}

	return 0;

	}
