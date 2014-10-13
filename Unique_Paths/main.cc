#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	int uniquePaths(int m, int n) {
		if(n*m == 0)	return 0;
		vector<vector<int> >data(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++)
			data[i][0] = 1;
		for(int j = 0; j < n; j++)
			data[0][j] = 1;
		for(int i = 1; i < m; i++){
			for(int j = 1; j < n; j++)
				data[i][j] = data[i-1][j] + data[i][j-1];
		}
		return data[m-1][n-1];
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int ret = sl.uniquePaths(1,2);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
