#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	bool preprocess(vector<vector<bool> > &row,
					vector<vector<bool> > &col,
					vector<vector<bool> > &area,
					vector<vector<char> > &board){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j] != '.'){
					if(row[i][board[i][j] - '1'] == false)
						return false;
					row[i][board[i][j] - '1'] = false;
				}
			}
		}

		for(int j = 0; j < 9; j++){
			for(int i = 0; i < 9; i++){
				if(board[i][j] != '.'){
					if(col[j][board[i][j] - '1'] == false)
						return false;
					col[j][board[i][j] - '1'] = false;
				}
			}
		}
	
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j] != '.'){
					if(area[(i/3)*3 + j/3][board[i][j] - '1'] == false)
						return false;
					area[(i/3)*3 + j/3][board[i][j] - '1'] = false;
				}
			}
		}

		return true;
	}

	bool isValidSudoku(vector<vector<char> > &board) {
		vector<vector<bool> > row(9, vector<bool>(9, true));
		vector<vector<bool> > col(9, vector<bool>(9, true));
		vector<vector<bool> > area(9, vector<bool>(9, true));
		
		return preprocess(row, col, area, board);
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

	bool ret = sl.isValidSudoku(data);
	
	cout<<ret<<endl;

	cout<<"After"<<endl;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++)
			cout<<data[i][j]<<" ";
		cout<<endl;
	}

	return 0;

}
