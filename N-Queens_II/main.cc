#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

	int recursion(int n, int pos, vector<vector<bool> > &mark) {
		if(pos == 0){
			for(int i = 0; i < mark[0].size(); i++)
				if(mark[0][i]){
					return 1;
				}
			return 0;
		}

		int data = 0;
		vector<vector<bool> > backup(3, vector<bool>(n, true));
		for(int i = 0; i < mark[pos].size(); i++){
			if(mark[pos][i]){

				for(int j = 0; j < mark[pos].size(); j++){
					if(j < pos){
						backup[0][j] = mark[j][i];
						mark[j][i] = false;
					}
					if( j != 0 && i-j >= 0 && pos - j >= 0){
						backup[1][j] = mark[pos-j][i-j];
						mark[pos-j][i-j] = false;
					}
					if(j != 0 && i+j < n && pos - j >= 0){
						backup[2][j] = mark[pos-j][i+j];
						mark[pos-j][i+j] = false;
					}
				}

				int sub = recursion(n, pos-1, mark);

				if(sub){
					data = data + sub;
				}

				for(int j = 0; j < mark[pos].size(); j++){
					if(j <= pos){
						mark[j][i] = backup[0][j];
					}
					if(j != 0 && i-j >= 0 && pos - j >= 0){
						mark[pos-j][i-j] = backup[1][j];
					}
					if(j != 0 && i+j < n && pos - j >= 0){
						mark[pos-j][i+j] = backup[2][j];
					}
				}

			}
		}
		return data;
    }

	int totalNQueens_1st(int n) {
		vector<vector<bool> > mark(n, vector<bool>(n, true));
		return recursion(n, n-1, mark);
    }

	bool isSafe(vector<pair<int, int> > &queens, int i, int j){
		for(int k = 0; k < queens.size(); k++){
			int x = queens[k].first, y = queens[k].second;
			if(x == i || y == j || abs(i - x) == abs(j - y))
				return false;
		}
		return true;
	}

	void backtrack(int &result, vector<pair<int, int> > &queens,
					int row, int row_num){
		if(row == row_num){
			result++;
			return;
		}
		for(int i = 0; i < row_num; i++){
			if(isSafe(queens, row, i)){
				queens.push_back(make_pair(row, i));
				backtrack(result, queens, row+1, row_num);
				queens.pop_back();
			}
		}
	}

	int totalNQueens(int n) {
		if(n <= 0)	return 0;
		vector<pair<int, int> > queens;
		int result = 0;
		backtrack(result, queens, 0, n);
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	
    int ret = sl.totalNQueens(5);
	
	cout<<ret<<endl;

	return 0;

}
