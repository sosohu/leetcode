#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void print(vector<vector<char> > data){
	cout<<"PRINT MSG"<<endl;
	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size(); j++){
			cout<<data[i][j]<<" ";
		}
		cout<<endl;
	}

}

class Solution {

public:

	void solve(vector<vector<char> > &board) {
		int row = board.size();	

		vector<vector<bool> > find;

		for(int i = 0; i < board.size(); i++){
			vector<bool> find_item;
			for(int j = 0; j < board[i].size(); j++)
				find_item.push_back(false);
			find.push_back(find_item);
		}


		typedef pair<int, int> item;
		stack<item>	s;
		item tmp;
		for(int i = 0; i < board.size(); i++){
			int col = board[i].size();
			if(i != 0 && i != row - 1){
				if(board[i][0] == 'O'){
					tmp.first = i;
					tmp.second = 0;
					s.push(tmp);
					find[i][0] = true;
				}
				if(board[i][col-1] == 'O'){
					tmp.first = i;
					tmp.second = col - 1;
					s.push(tmp);
					find[i][col-1] = true;
				}
				continue;
			}
			for(int j = 0; j < col; j++){
				if(board[i][j] == 'O'){
					tmp.first = i;
					tmp.second = j;
					s.push(tmp);
					find[i][j] = true;
				}
			}
		}

		int x,y;
		while(!s.empty()){
			tmp = s.top();
			s.pop();
			x = tmp.first;
			y = tmp.second;
			if(x-1 >= 0 && board[x-1][y] == 'O' && find[x-1][y] == false){
				find[x-1][y] = true;
				tmp.first = x -1;
				tmp.second = y;
				s.push(tmp);
			}
			if(y-1 >= 0 && board[x][y-1] == 'O' && find[x][y-1] == false){
				find[x][y-1] = true;
				tmp.first = x;
				tmp.second = y - 1;
				s.push(tmp);
			}
			if(x+1 < board.size() && board[x+1][y] == 'O' && find[x+1][y] == false){
				find[x+1][y] = true;
				tmp.first = x + 1;
				tmp.second = y;
				s.push(tmp);
			}
			if(y+1 < board[x].size() && board[x][y+1] == 'O' && find[x][y+1] == false){
				find[x][y+1] = true;
				tmp.first = x;
				tmp.second = y + 1;
				s.push(tmp);
			}
		}
		
		for(int i = 0; i < board.size(); i++){
			for(int j = 0; j < board[i].size(); j++){
				if(!find[i][j])
					board[i][j] = 'X';
			}
		}
		return;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<char> > data;
	for(int i = 0; i < 4; i++){
		vector<char> tmp;
		for(int j = 0; j < 4; j++){
			tmp.push_back('X');
		}
		data.push_back(tmp);
	}

	data[0][1] = 'O';
	data[1][0] = 'O';
	data[1][2] = 'O';
	data[2][1] = 'O';
	data[2][3] = 'O';
	data[3][0] = 'O';
	data[3][2] = 'O';

	print(data);

    sl.solve(data);
	
	print(data);

	return 0;

}
