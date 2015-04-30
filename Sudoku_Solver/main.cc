#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<char> row[9]; 
unordered_set<char> col[9]; 
unordered_set<char> area[9]; 


class Solution {

public:

	void preprocess(vector<vector<bool> > &row,
					vector<vector<bool> > &col,
					vector<vector<bool> > &area,
					vector<vector<char> > &board,
					vector<vector<vector<bool> > > &mark){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j] != '.'){
					row[i][board[i][j] - '1'] = false;
				}
			}
		}

		for(int j = 0; j < 9; j++){
			for(int i = 0; i < 9; i++){
				if(board[i][j] != '.'){
					col[j][board[i][j] - '1'] = false;
				}
			}
		}
	
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j] != '.'){
					area[(i/3)*3 + j/3][board[i][j] - '1'] = false;
				}
			}
		}

		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++){
				for(int k = 0; k < 9; k++)
				mark[i][j][k] = mark[i][j][k] && row[i][k] && col[j][k] 
								&& area[(i/3)*3 + j/3][k];
			}
	}

	bool recursion(vector<vector<char> > &board,
				   vector<vector<vector<bool> > > &mark){
		int i , j;
		for(i = 0; i < 9; i++){
			for(j = 0; j < 9; j++){
				if(board[i][j] == '.')
					break;
			}
			if(j < 9 && board[i][j] == '.')
				break;
		}
		if(i == 9 && j == 9)	return true;

		for(int k = 0; k < 9; k++){
			if(mark[i][j][k]){
				// prepare
				board[i][j] = '1' + k;
				vector<bool> back_row(9, true);
				vector<bool> back_col(9, true);
				vector<bool> back_area(9, true);
				for(int p = 0; p < 9; p++){
					back_row[p] = mark[i][p][k];
					mark[i][p][k] = false;
				}
				for(int p = 0; p < 9; p++){
					back_col[p] = mark[p][j][k];
					mark[p][j][k] = false;
				}
				for(int p = 0; p < 3; p++){
					for(int q = 0; q < 3; q++){
						back_area[p*3 + q] = mark[(i/3)*3 + p][(j/3)*3 + q][k];
						mark[(i/3)*3+p][(j/3)*3+q][k] = false;
					}
				}

				bool sub = recursion(board, mark);
				if(sub)
					return true;
				// recover
				board[i][j] = '.';
				for(int p = 0; p < 3; p++){
					for(int q = 0; q < 3; q++){
						mark[(i/3)*3+p][(j/3)*3+q][k] = back_area[p*3 + q];
					}
				}
				for(int p = 0; p < 9; p++){
					mark[p][j][k] = back_col[p];
				}
				for(int p = 0; p < 9; p++){
					mark[i][p][k] = back_row[p];
				}
			}
		}
		return false;
	}

	void solveSudoku_1st(vector<vector<char> > &board) {
		vector<vector<bool> > row(9, vector<bool>(9, true));
		vector<vector<bool> > col(9, vector<bool>(9, true));
		vector<vector<bool> > area(9, vector<bool>(9, true));
		vector<vector<vector<bool> > > mark(9, vector<vector<bool> >(9, vector<bool>(9, true)));
		
		preprocess(row, col, area, board, mark);

	
		recursion(board, mark);
    }

	bool dfs(vector<vector<char> > &board, int i, int j){
		if(i == 9)	return true;
		if(board[i][j] != '.'){
			i = j == 8? i+1 : i;
			j = j == 8? 0 : j+1;
			return dfs(board, i, j);
		}else{
			for(int k = 1; k <= 9; k++){
				char cur = '0' + k;
				if(!row[i].count(cur) && !col[j].count(cur) 
					&& !area[(i/3)*3 + j/3].count(cur)){
					row[i].insert(cur);
					col[j].insert(cur);
					area[(i/3)*3 + j/3].insert(cur);
					board[i][j] = cur;
					i = j == 8? i+1 : i;
					j = j == 8? 0 : j+1;
					if(dfs(board, i, j))	return true;
					i = j == 0? i-1 : i;
					j = j == 0? 8 : j-1;
					row[i].erase(cur);
					col[j].erase(cur);
					area[(i/3)*3 + j/3].erase(cur);
				}
			}
			board[i][j] = '.';
			return false;
		}
	}

	void solveSudoku(vector<vector<char> > &board) {
		for(int i = 0; i < 9; i++){
			row[i].clear();
			col[i].clear();
			area[i].clear();
		}
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++){
				if(board[i][j] != '.'){
					row[i].insert(board[i][j]);
					col[j].insert(board[i][j]);
					area[(i/3)*3+j/3].insert(board[i][j]);
				}
			}
		dfs(board, 0, 0);
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<char> > data(9, vector<char>(9, '.'));
	string content[] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};

	int i;
	int margin, start;
	for(i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			data[i][j] = content[i][j];
		}
	}

	//cout<<"LINE "<<__LINE__<<endl;

	cout<<"Before"<<endl;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++)
			cout<<data[i][j]<<" ";
		cout<<endl;
	}

	sl.solveSudoku(data);
	
	cout<<"After"<<endl;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++)
			cout<<data[i][j]<<" ";
		cout<<endl;
	}

	return 0;

}
