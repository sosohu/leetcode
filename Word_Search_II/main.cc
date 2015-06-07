#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
	char val;
	bool isNode;
	TrieNode *sons[26];
public:
    // Initialize your data structure here.
    TrieNode(char val = '-', bool isNode = false)
	: val(val), isNode(isNode) {
		for(int i = 0; i < 26; i++)
			sons[i] = NULL;
    }
};

class Solution {
public:
	Solution(){
		root = new TrieNode();
	}

    void insert(string &s) {
		TrieNode *pos = root;
		for(int i = 0; i < s.size(); i++){
			int index = s[i] - 'a';
			if(pos->sons[index] == NULL)
				pos->sons[index] = new TrieNode(s[i]);
			pos = pos->sons[index];
		}
		pos->isNode = true;
    }

	void build(vector<string> &words){
		for(int i = 0; i < words.size(); i++)
			insert(words[i]);
	}

	void backtrack(vector<vector<char> > &board, vector<string> &result, 
					TrieNode *pos, string &trace, int i, int j, int n, int m){
		if(board[i][j] == 'X')	return;
		if(pos->sons[board[i][j] - 'a'] == NULL)	return;
		trace.push_back(board[i][j]);
		if(pos->sons[board[i][j] - 'a']->isNode){
			result.push_back(trace);
			pos->sons[board[i][j] - 'a']->isNode = false; // avoid the duplicate result
		}
		char tmp = board[i][j];
		board[i][j] = 'X';
		if(i > 0)	backtrack(board, result, pos->sons[tmp - 'a'], trace, i-1, j, n, m);
		if(i < n-1)	backtrack(board, result, pos->sons[tmp - 'a'], trace, i+1, j, n, m);
		if(j > 0)	backtrack(board, result, pos->sons[tmp - 'a'], trace, i, j-1, n, m);
		if(j < m-1)	backtrack(board, result, pos->sons[tmp - 'a'], trace, i, j+1, n, m);
		board[i][j] = tmp;
		trace.erase(trace.begin() + trace.size() - 1);
	}

	vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
		vector<string> result;
		int n = board.size();
		if(n == 0) return result;
		int m = board[0].size();
		build(words);
		string trace;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				backtrack(board, result, root, trace, i, j, n, m);
		return result;
	}

private:
    TrieNode* root;
};

int main(int argc, char** argv)
{
	Solution sl;
	vector<string> words{"abbbababaa"};

	vector<vector<char> > board{{'b','b','a','a','b','a'},
								{'b','b','a','b','a','a'},
								{'b','b','b','b','b','b'},
								{'a','a','a','b','a','a'},
								{'a','b','a','a','b','b'}};
	vector<string> result = sl.findWords(board, words);
	for(auto ele : result)
		cout<<ele<<endl;

	return 0;

}
