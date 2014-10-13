#include <iostream>
#include <string>
#include <vector>

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

	int maximalRectangle(vector<vector<char> > &matrix) {
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

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<char> > data(4, vector<char>(5, '0'));
	data[0][0] = '1';
	data[0][2] = '1';
	data[1][2] = '1';
	data[1][3] = '1';
	data[1][4] = '1';
	data[2][1] = '1';
	data[2][3] = '1';
	data[3][3] = '1';
	data[3][4] = '1';
	
	print(data, "data");
	int ret = sl.maximalRectangle(data);

	cout<<ret<<endl;

	return 0;

}
