#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {

public:

	void visit(vector<vector<char> > &grid, vector<vector<bool> > &visited,
			 	queue<pair<int, int> > &q, int n, int m, int i, int j){
		if(i < 0 || j < 0 || i > n-1 || j > m-1 || 
			grid[i][j] == '0' || visited[i][j])	return;
		visited[i][j] = true;
		q.push(make_pair(i,j));
	}

	void bfs(vector<vector<char> > &grid, vector<vector<bool> > &visited,
			 int n, int m, int i, int j){
		queue<pair<int, int> > q;
		q.push(make_pair(i, j));
		pair<int,int> cur;
		visited[i][j] = true;
		while(!q.empty()){
			cur = q.front();
			q.pop();
			i = cur.first;
			j = cur.second;
			visit(grid, visited, q, n, m, i+1, j);
			visit(grid, visited, q, n, m, i-1, j);
			visit(grid, visited, q, n, m, i, j-1);
			visit(grid, visited, q, n, m, i, j+1);
		}
	}

	int numIslands(vector<vector<char> >& grid) {
		int n = grid.size();
		if(n == 0)	return 0;
		int m = grid[0].size();
		vector<vector<bool> > visited(n, vector<bool>(m, false));
		int count = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(!visited[i][j] && grid[i][j] == '1'){
					count++;
					bfs(grid, visited, n, m, i, j);
				}
		return count;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<char> > grid(3, vector<char>(3, '1'));
	grid[1][0] = '0';
	grid[1][2] = '0';
	cout<<sl.numIslands(grid)<<endl;
	return 0;

}
