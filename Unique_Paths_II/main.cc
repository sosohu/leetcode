#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	int uniquePathsWithObstacles_1st(vector<vector<int> > &obstacleGrid) {
		int n = obstacleGrid.size();
		if(n == 0)	return 0;
		int m = obstacleGrid[0].size();
		if(m == 0)	return 0;
		vector<vector<int> > data(n, vector<int>(m, 0));
		if(obstacleGrid[0][0] == 1)	return 0;
	
		data[0][0] = 1;
		for(int i = 1; i < n; i++)
			if(obstacleGrid[i][0] == 0 && data[i-1][0] != 0)
				data[i][0] = 1;
		for(int j = 1; j < m; j++)
			if(obstacleGrid[0][j] == 0 && data[0][j-1] != 0)
				data[0][j] = 1;
		
		for(int i = 1; i < n; i++){
			for(int j = 1; j < m; j++){
				if(obstacleGrid[i][j] == 0){
					data[i][j] = data[i-1][j] + data[i][j-1];
				}	
			}
		}
		return data[n-1][m-1];
    }

	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int> > dp(m, vector<int>(n, 1));
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++){
				if(obstacleGrid[i][j])	dp[i][j] = 0;
				else{
					if(i + j != 0)
						dp[i][j] = (i > 0? dp[i-1][j] : 0) + (j > 0? dp[i][j-1] : 0);
				}
			}
		return dp[m-1][n-1];
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> > obstacleGrid(3, vector<int>(3, 0));
	obstacleGrid[1][1] = 1;
	int ret = sl.uniquePathsWithObstacles(obstacleGrid);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
