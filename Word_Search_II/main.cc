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

	void backtrack(TrieNode *pos, vector<vector<char> > &board, vector<vector<bool> > &used,
					int i, int j, int n, int m){
		if(i < 0|| i >= n || j < 0 || j >= m || used[i][j])	return;
		used[i][j] = true;
		int index = board[i][j] - 'a';
		if(pos->sons[index] == NULL){
			pos->sons[index] = new TrieNode(board[i][j]);
		}
		pos->sons[index]->isNode = true;
		backtrack(pos->sons[index], board, used, i+1, j, n, m);
		backtrack(pos->sons[index], board, used, i-1, j, n, m);
		backtrack(pos->sons[index], board, used, i, j+1, n, m);
		backtrack(pos->sons[index], board, used, i, j-1, n, m);
		used[i][j] = false;
	}

	vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
		vector<string> result;
		int n = board.size();
		if(n == 0) return result;
		int m = board[0].size();
		vector<vector<bool> > used(n, vector<bool>(m, false));
		string trace;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				backtrack(root, board, used, i, j, n, m);
		for(int i = 0; i < words.size(); i++){
			if(search(words[i]))
				result.push_back(words[i]);
		}
		return result;
	}

    bool search(string key) {
		TrieNode *pos = root;
		for(int i = 0; i < key.size(); i++){
			int index = key[i] - 'a';
			if(pos->sons[index] == NULL)
				return false;
			pos = pos->sons[index];
		}
		return pos->isNode;
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
