#include <iostream>
#include <string>
#include <vector>

using namespace std;


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

	void solveSudoku(vector<vector<char> > &board) {
		vector<vector<bool> > row(9, vector<bool>(9, true));
		vector<vector<bool> > col(9, vector<bool>(9, true));
		vector<vector<bool> > area(9, vector<bool>(9, true));
		vector<vector<vector<bool> > > mark(9, vector<vector<bool> >(9, vector<bool>(9, true)));
		
		preprocess(row, col, area, board, mark);

	
		recursion(board, mark);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<char> > data(9, vector<char>(9, '.'));
	string content[] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};

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
