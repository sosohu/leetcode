#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
		int n = board.size();
		if(n == 0)	return;
		int m = board[0].size();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int count = getNumLiveNeigh(board, i, j, n, m);
				if(board[i][j]){
					if(count < 2 || count > 3){
						board[i][j] = INT_MIN;
					}
				}else{
					if(count == 3){
						board[i][j] = INT_MAX;
					}
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(board[i][j] == INT_MIN)	board[i][j] = 0;
				if(board[i][j] == INT_MAX)	board[i][j] = 1;
			}
		}
    }

	void getNumLiveNeigh_aux(vector<vector<int>> &board, int &count, int i, int j, int n, int m){
		if(i < 0 || j < 0 || i == n || j == m)	return;
		if(board[i][j] == 1 || board[i][j] == INT_MIN)	count++;
	}

	int getNumLiveNeigh(vector<vector<int>> &board, int i, int j, int n, int m){
		int count = 0;
		for(int ii = i - 1; ii <= i + 1; ii++){
			for(int jj = j - 1; jj <= j + 1; jj++){
				if(ii != i || jj != j){
					getNumLiveNeigh_aux(board, count, ii, jj, n, m);
				}
			}
		}
		return count;
	}
};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int>> data{{1, 1, 1}, {0, 0, 0}, {1, 1, 1}};
	sl.gameOfLife(data);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
			cout<<data[i][j]<<" ";
		cout<<endl;
	}
	return 0;

}
