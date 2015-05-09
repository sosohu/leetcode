#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>

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

	void solve_1st(vector<vector<char> > &board) {
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

	void visit(vector<vector<char> >& board, queue<pair<int, int> > &search, 
				int n, int m, int i, int j){
		if(i < 0 || i > n-1 || j < 0 || j > m-1 || board[i][j] != 'O')	return;
		search.push(make_pair(i, j));
		board[i][j] = '-';
	}

	void bfs(vector<vector<char> > &board, int n, int m, int i, int j){
		if(board[i][j] != 'O')	return;
		queue<pair<int,int> > search;
		pair<int, int> cur;
		search.push(make_pair(i, j));
		board[i][j] = '-';
		while(!search.empty()){
			cur = search.front();
			search.pop();
			i = cur.first;
			j = cur.second;
			visit(board, search, n, m, i-1, j);
			visit(board, search, n, m, i+1, j);
			visit(board, search, n, m, i, j-1);
			visit(board, search, n, m, i, j+1);
		}
	}

	void solve(vector<vector<char> > &board) {
		int n = board.size();
		if(n == 0) return;
		int m = board[0].size();
		//从四个边开始搜,那么找到的必然是活的
		for(int i = 0; i < n; i++){
			bfs(board, n, m, i, 0);
			bfs(board, n, m, i, m-1);
		}
		for(int j = 0; j < m; j++){
			bfs(board, n, m, 0, j);
			bfs(board, n, m, n-1, j);
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				if(board[i][j] == 'O') board[i][j] = 'X';
				if(board[i][j] == '-') board[i][j] = 'O';
		}
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
