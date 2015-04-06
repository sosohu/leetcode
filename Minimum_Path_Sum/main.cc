#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


class Solution {

public:

	int minPathSum_1st(vector<vector<int> > &grid) {
		int n = grid.size();
		if(n == 0)	return 0;
		int m = grid[0].size();
		if(m == 0)	return 0;

		vector<vector<int> > data(n, vector<int>(m, 0));
		data[0][0] = grid[0][0];
		for(int i = 1; i < n; i++){
			data[i][0] = data[i-1][0] + grid[i][0];
		}
		for(int j = 1; j < m; j++){
			data[0][j] = data[0][j-1] + grid[0][j];
		}
		int down, right;
		for(int i = 1; i < n; i++){
			for(int j = 1; j < m; j++){
				down = data[i-1][j] + grid[i][j];
				right = data[i][j-1] + grid[i][j];
				data[i][j] = down < right? down : right;
			}
		}
		return data[n-1][m-1];
    }

	int minPathSum(vector<vector<int> > &grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int> > dp(grid);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				if(i + j != 0){
					dp[i][j] = grid[i][j] + 
							min((i > 0? dp[i-1][j] : INT_MAX), (j > 0? dp[i][j-1] : INT_MAX));
				}
			}
		return dp[n-1][m-1];
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> > grid(3, vector<int>(3, 0));
	int data[3][3] = {{1, 2, 5},
					  {4, 5, 2},
					  {1, 1, 3}};
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			grid[i][j] = data[i][j];

	int ret = sl.minPathSum(grid);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
