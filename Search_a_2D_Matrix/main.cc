#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int n = matrix.size();
		if(n == 0)	return false;
		int m = matrix[0].size();
		if(m == 0)  return false;

		int low = 0, high = n - 1, mid;
		while(low <= high){
			mid = (low + high) / 2;
			if(matrix[mid][0] <= target && matrix[mid][m-1] >= target)
				break;
			if(target < matrix[mid][0])
				high = mid - 1;
			if(target > matrix[mid][m-1])
				low = mid + 1;
		}
		if(low > high)
			return false;
		int cur = mid;
		low = 0;
		high = m-1;
		while(low <= high){
			mid = (low + high) / 2;
			if(matrix[cur][mid] == target)
				return true;
			if(target < matrix[cur][mid])
				high = mid - 1;
			if(target > matrix[cur][mid])
				low = mid + 1;
		}
		return false;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> > data(3, vector<int>(4, 0));
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			data[i][j] = i*4 + j;
		}	
	}
	bool ret = sl.searchMatrix(data, 13);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
