#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

template<class T>
void print(vector<vector<T> > data, string msg = ""){
	cout<<"PRINT "<<msg<<endl;
	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size(); j++){
			cout<<data[i][j]<<" ";
		}
		cout<<endl;
	}	
}


class Solution {

	class mysort{
		bool operator()(int i, int j){
			return i < j;
		}
	} mysort;

public:

	int maximalRectangle_1st(vector<vector<char> > &matrix) {
		int n = matrix.size();
		if(n == 0)	return 0;

		int  m = matrix[0].size();

		vector<vector<int> > down(n, vector<int>(m, 0)); // down[i][j] record how many continues '1' underside of matrix[i][j], when matrix[i][j] == 1

		for(int j = 0; j < m; j++){
			for(int i = 0; i < n; i++){
				if(matrix[i][j] == '1'){
					int k;
					for(k = i + 1; k < n; k++){
						if(matrix[k][j] == '0') break;
					}	
					down[k-1][j] = 0;
					for(int d = k -2; d >= i; d--){
						down[d][j] = down[d+1][j] + 1;
					}
					i = k;
				}
			}
		}
		
		print(down, "down");

		int pre, tmp, min;
		pre = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(matrix[i][j] == '1'){
					min = down[i][j];
					int  k;
					tmp = min + 1;
					if(tmp > pre) pre = tmp;
					for(k = j + 1; k < m; k++){
						if(matrix[i][k] == '0') break;
						if(min > down[i][k])	min = down[i][k];
						tmp = (min + 1)*(k + 1 - j);
						if(tmp > pre) pre = tmp;
					}
				}
			}
		}
		return pre;
    }

	int maximalRectangle(vector<vector<char> > &matrix){ 
		int n = matrix.size();
		if(n == 0)	return 0;
		int m = matrix[0].size();
		vector<vector<int> > height(n, vector<int>(m, 0)); //悬线,包含本元素
		vector<vector<int> > left(n, vector<int>(m, 0)); //左边,包含本元素
		vector<vector<int> > right(n, vector<int>(m, 0)); //右边,包含本元素
		//计算悬线
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				if(matrix[i][j] != '0'){
					height[i][j] = i == 0? 1 : height[i-1][j] + 1;
				}
			}
		//计算左边界
		for(int i = 0; i < n; i++){
			int left_zero = -1;
			for(int j = 0; j < m; j++){
				if(matrix[i][j] != '0'){
					if(j == 0) left[i][j] = 1;
					else{
						if(height[i][j] == 1){
							left[i][j] = j - left_zero;
						}else{
							left[i][j] = min(j - left_zero, left[i-1][j]);
						}
					}
				}else{
					left_zero = j;
				}
			}
		}
		//计算右边界
		for(int i = 0; i < n; i++){
			int right_zero = m;
			for(int j = m-1; j >= 0; j--){
				if(matrix[i][j] != '0'){
					if(j == m-1)	right[i][j] = 1;
					else{
						if(height[i][j] == 1){
							right[i][j] = right_zero - j;
						}else{
							right[i][j] = min(right_zero - j, right[i-1][j]);
						}
					}
				}else{
					right_zero = j;
				}
			}
		}
		print(height, "悬线");
		print(left, "左边");
		print(right, "右边");
		//计算每个悬线左右扫描确定的极大子矩阵
		int maxRect = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(matrix[i][j] != '0'){
					int cur = height[i][j]*(left[i][j] + right[i][j] - 1);
					maxRect = max(maxRect, cur);
				}
			}
		}
		return maxRect;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<char> > data(4, vector<char>(4, '0'));
	data[0][0] = '1';
	data[0][2] = '1';
	data[1][0] = '1';
	data[1][2] = '1';
	data[1][3] = '1';
	data[2][0] = '1';
	data[2][2] = '1';
	data[2][3] = '1';
	data[3][0] = '1';
	data[3][1] = '1';
	data[3][2] = '1';
	data[3][3] = '1';
	
	print(data, "data");
	int ret = sl.maximalRectangle(data);

	cout<<ret<<endl;

	return 0;

}
