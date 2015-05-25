#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	vector<int> spiralOrder_1st(vector<vector<int> > &matrix) {
		int n = matrix.size();
		if(n == 0){
			vector<int> data;
			return data;
		}
		int m = matrix[0].size();
		vector<int> data(n*m, 0);
		if(m == 0)	return data;

		int x = 0, y = 0;
		int start = 0;

		while(x < m/2 && y < n/2){
			for(int j = x; j < m - x; j++)
				data[start++] = matrix[y][j];
			for(int i = y + 1; i < n - y; i++)
				data[start++] = matrix[i][m-x-1];
			for(int j = m - x -2; j >= x; j--)
				data[start++] = matrix[n-y-1][j];
			for(int i = n -y - 2; i >= y + 1; i--)
				data[start++] = matrix[i][x];
			x++;
			y++;
		}
		if(m <= n && x*2 != m){
			for(int i = y; i < n - y; i++)
				data[start++] = matrix[i][x];
		}
		if(m > n && y*2 != n){
			for(int j = x; j < m - x; j++)
				data[start++] = matrix[y][j];
		}
		return data;
    }

	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> result;
		int n = matrix.size();
		if(n == 0)	return result;
		int m = matrix[0].size();
		int magrin = 0;
		while(m - 1 - magrin >= magrin && n - 1 - magrin >= magrin){
			for(int j = magrin; j <= m - 1 - magrin; j++)
				result.push_back(matrix[magrin][j]);
			for(int i = magrin + 1; i < n - 1 - magrin; i++)
				result.push_back(matrix[i][m-1-magrin]);
			if(n - 1 - magrin != magrin)
				for(int j = m - 1 - magrin; j >= magrin; j-- )
					result.push_back(matrix[n-1-magrin][j]);
			if(m - 1 - magrin != magrin)
				for(int i = n - 1 - magrin - 1; i > magrin; i--)
					result.push_back(matrix[i][magrin]);
			magrin++;
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> > matrix(3, vector<int>(3, 0));

	for(int i = 0; i < matrix.size(); i++)
		for(int j = 0; j < matrix[i].size(); j++)
			matrix[i][j] = i*3 + j;

	vector<int> ret = sl.spiralOrder(matrix);
	
	for(int i = 0; i < ret.size(); i++)
		cout<<ret[i]<<endl;

	return 0;

}
