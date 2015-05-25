#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

	void rotate_1st(vector<vector<int> > &matrix) {
		int n = matrix.size();
		if(n == 0)	return;

		for(int i = 0; i < n/2; i++){
			matrix[i].swap(matrix[n-1-i]);
		}	
		int tmp;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;
			}
		}
    }

	void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		for(int i = 0; i < n; i++){
			reverse(matrix[i].begin(), matrix[i].end());
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n - 1 - i; j++){
				swap(matrix[i][j], matrix[n-1-j][n-1-i]);
			}
		}
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> > matrix(3, vector<int>(3, 0));
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++)
			matrix[i][j] = i*matrix.size() + j;
	}
	
	sl.rotate(matrix);
	
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}

	return 0;

}
