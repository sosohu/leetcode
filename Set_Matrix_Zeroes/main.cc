#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	void setZeroes_1st(vector<vector<int> > &matrix) {
		int n = matrix.size();
		if(n == 0) return;
		int m = matrix[0].size();
		if(m == 0) return;

		int orign = matrix[0][0];
		for(int i = 0; i < n; i++)
			if(matrix[i][0] == 0){
				orign = 0;
				break;
			}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(matrix[i][j] == 0){
					matrix[i][0] = 0;
					break;
				}
			}
		}
		for(int j = 1; j < m; j++){
			for(int i = 0; i < n; i++){
				if(matrix[i][j] == 0){
					matrix[0][j] = 0;
					break;
				}
			}
		}

		for(int i = 1; i < n; i++){
			if(matrix[i][0] == 0){
				for(int j = 1; j < m; j++)
					matrix[i][j] = 0;
			}
		}	
		for(int j = 1; j < m; j++){
			if(matrix[0][j] == 0){
				for(int i = 1; i < n; i++)
					matrix[i][j] = 0;
			}
		}
		
		if(matrix[0][0] == 0){
			for(int j = 0; j < m; j++)
				matrix[0][j] = 0;
		}

		if(orign == 0){
			for(int i = 0; i < n; i++)
				matrix[i][0] = 0;
		}
    }

	void setZeroes(vector<vector<int> > &matrix) {
		int n = matrix.size();
		if(n == 0)	return;
		int m = matrix[0].size();
		bool lastZero = false;
		for(int i = 0; i < n; i++){
			bool thisZero = false;
			for(int j = 0; j < m; j++){
				if(matrix[i][j] == 0){
					int up = i - 1;
					while(up >= 0){
						matrix[up][j] = 0;
						up--;
					}
					thisZero = true;
				}
				if(i > 0 && matrix[i-1][j] == 0)
					matrix[i][j] = 0;
			}
			if(lastZero){
				for(int j = 0; j < m; j++)
					matrix[i-1][j] = 0;
			}
			lastZero = thisZero;
		}
		if(lastZero){
			for(int j = 0; j < m; j++)
				matrix[n-1][j] = 0;
		}
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> > data(1, vector<int>(2, 0));
	for(int i = 0; i < 1; i++){
		for(int j = 0; j < 2; j++){
			data[i][j] = i + j;
		}	
	}
	data[0][0] = 1;
	data[0][1] = 0;

	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size(); j++)
			cout<<data[i][j]<<" ";
		cout<<endl;
	}

	sl.setZeroes(data);
	
	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size(); j++)
			cout<<data[i][j]<<" ";
		cout<<endl;
	}

	return 0;

}
