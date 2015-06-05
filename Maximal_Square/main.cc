#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

	int maximalSquare(vector<vector<char> >& matrix) {
		int n = matrix.size();
		if(n == 0)	return 0;
		int m = matrix[0].size();
		vector<vector<int> > line(n, vector<int>(m, 0));
		vector<vector<int> > left(n, vector<int>(m, 0));
		vector<vector<int> > right(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				line[i][j] = (matrix[i][j] == '0')? 0 : (i == 0? 1 : line[i-1][j] + 1);
			}
		}
		for(int i = 0; i < n; i++){
			int left_zero = -1;
			for(int j = 0; j < m; j++){
				if(matrix[i][j] == '0'){
					left_zero = j;
					left[i][j] = 0;
				}else{
					left[i][j] = (j == 0)? 1 : 
									(i == 0 || matrix[i-1][j] == '0'? j - left_zero : 
											min(j - left_zero, left[i-1][j]));
				}
			}
			int right_zero = m;
			for(int j = m-1; j >= 0; j--){
				if(matrix[i][j] == '0'){
					right_zero = j;
					right[i][j] = 0;
				}else{
					right[i][j] = (j == m-1)? 1 : 
										(i == 0 || matrix[i-1][j] == '0'? right_zero - j :
											 min(right_zero - j, right[i-1][j]));
				}
			}
		}
		int ret = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				if(matrix[i][j] == '1')
					if(left[i][j] + right[i][j] - 1 >= line[i][j])
						ret = max(ret, line[i][j] * line[i][j]);	
			}
		return ret;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<char> > matrix{{'1','0','1','0','0'},
								 {'1','0','1','1','1'},
								 {'1','1','1','1','1'},
								 {'1','0','0','1','0'}};
	cout<<sl.maximalSquare(matrix)<<endl;						

	return 0;

}
