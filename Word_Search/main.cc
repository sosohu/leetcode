#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>
void print(vector<vector<T> >& data, string str = ""){
	cout<<"PRINT "<<str<<endl;
	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size(); j++)
			cout<<data[i][j]<<" ";
		cout<<endl;
	}
}

class Solution {

public:

	bool BFS(vector<vector<char> > &board, string& word, 
			 vector<vector<bool> > &mark,  
			 int n, int m, int len, int i, int j, int k){
		mark[i][j] = false;
		if(word[k] != board[i][j]) return false;
		if(k == len - 1)
			return true;
		int ret = false;
		bool tmp;
		if(i > 0 && board[i-1][j] == word[k+1] && mark[i-1][j]){
			tmp = mark[i-1][j];
			ret = ret || BFS(board, word, mark, n, m, len, i-1, j, k+1);
			mark[i-1][j] = tmp;
		}
		if(j > 0 && board[i][j-1] == word[k+1] && mark[i][j-1]){
			tmp = mark[i][j-1];
			ret = ret || BFS(board, word, mark, n, m, len, i, j-1, k+1);
			mark[i][j-1] = tmp;
		}
		if(i < n - 1 && board[i+1][j] == word[k+1] && mark[i+1][j]){
			tmp = mark[i+1][j];
			ret = ret || BFS(board, word, mark, n, m, len, i+1, j, k+1);
			mark[i+1][j] = tmp;
		}
		if(j < m - 1 && board[i][j+1] == word[k+1] && mark[i][j+1]){
			tmp = mark[i][j+1];
			ret = ret || BFS(board, word, mark, n, m, len, i, j+1, k+1);
			mark[i][j+1] = tmp;
		}
		return ret;
	}

	bool exist(vector<vector<char> > &board, string word) {
		int len = word.length();
		int n = board.size();
		if(len == 0)	return true;
		if(n == 0)	return false;

		int m = board[0].size();
		vector<vector<bool> > mark(n, vector<bool>(m, true));
		
		#ifdef DEBUG
		cout<<n<<" "<<m<<endl;	
		#endif

		int ret = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				#ifdef DEBUG
				//print(mark, "mark");
				#endif
				if(board[i][j] == word[0]){
					ret = ret || BFS(board, word, mark, n, m, len, i, j, 0);
					mark[i][j] = true;
				}
			}
		}
		return ret;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	//char data[][4] = { {'a','a','a','a'}, {'a','a','a','a'}, {'a','a','a','a'}
	//					,{'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'b'}};
	char data[][3] = { {'C','A','A'}, {'A','A','A'}, {'B','C','D'}};
	//vector<vector<char> > board(5, vector<char>(4, '0'));
	vector<vector<char> > board(3, vector<char>(3, '0'));
	for(int i = 0; i < board.size(); i++)
		for(int j = 0; j < board[i].size(); j++)
			board[i][j] = data[i][j];
	//string word = "aaaaaaaaaaaaaaaaaaaa";
	string word = "AAB";
	
    int ret = sl.exist(board, word);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
