#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		if(n == 0)	return false;
		int m = matrix[0].size();
		return binarysearch(matrix, 0, n-1, 0, m-1, target);	
	}

	bool binarysearch(vector<vector<int>> &matrix, int up, int down, int left, int right, int target){
		if(up > down || left > right)	return false;
		if(down - up <= 1 && right - left <= 1){
			for(int i = up; i <= down; i++)
				for(int j = left; j <= right; j++)
					if(matrix[i][j]	== target)	return true;
			return false;
		}
		int x = (up + down) / 2, y = (left + right) / 2;
		if(matrix[x][y] == target)	return true;
		if(matrix[x][y] < target){
			return binarysearch(matrix, x+1, down, left, right, target) || binarysearch(matrix, up, x, y+1, right, target);
		}else{
			return binarysearch(matrix, up, x-1, left, right, target) || binarysearch(matrix, x, down, left, y-1, target);
		}
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int>> matrix{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
	cout<<sl.searchMatrix(matrix, 15)<<endl;
	return 0;
}
