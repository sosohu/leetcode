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

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
		TrieNode *pos = root;
		for(int i = 0; i < s.size(); i++){
			int index = s[i] - 'a';
			if(pos->sons[index] == NULL)
				pos->sons[index] = new TrieNode(s[i]);
			pos = pos->sons[index];
		}
		pos->isNode = true;
    }

    // Returns if the word is in the trie.
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

	// Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
		TrieNode *pos = root;
		for(int i = 0; i < prefix.size(); i++){
			int index = prefix[i] - 'a';
			if(pos->sons[index] == NULL)
				return false;
			pos = pos->sons[index];
		}
		return true;
    }

private:
    TrieNode* root;
};

class Solution {

public:

	void backtrack(Trie &root, vector<vector<char> > &board, vector<vector<bool> > &used,
					string &trace, int i, int j, int n, int m){
		if(i < 0|| i >= n || j < 0 || j >= m || used[i][j])	return;
		used[i][j] = true;
		trace.push_back(board[i][j]);
		backtrack(root, board, used, trace, i+1, j, n, m);
		backtrack(root, board, used, trace, i-1, j, n, m);
		backtrack(root, board, used, trace, i, j+1, n, m);
		backtrack(root, board, used, trace, i, j-1, n, m);
		root.insert(trace);
		trace.erase(trace.end() - 1);
		used[i][j] = false;
	}

	vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
		vector<string> result;
		int n = board.size();
		if(n == 0) return result;
		int m = board[0].size();
		vector<vector<bool> > used(n, vector<bool>(m, false));
		Trie tree;
		string trace;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				backtrack(tree,board,used,trace, i, j, n, m);
		for(int i = 0; i < words.size(); i++){
			if(tree.search(words[i]))
				result.push_back(words[i]);
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<string> words = {"oath","pea","eat","rain"};
	vector<vector<char> > board = {	{'o','a','a','n'},
  									{'e','t','a','e'},
			  						{'i','h','k','r'},
 				 					{'i','f','l','v'}
								  };
	vector<string> result = sl.findWords(board, words);
	for(auto ele : result)
		cout<<ele<<endl;

	return 0;

}
