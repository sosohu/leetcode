#include <iostream>

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
    void insert(const string &s) {
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

    bool searchReg(const string &key, TrieNode *pos = NULL, int begin = 0) {
		if(!pos)	pos = root;
		for(int i = begin; i < key.size(); i++){
			if(key[i] != '.'){
				int index = key[i] - 'a';
				if(pos->sons[index] == NULL)
					return false;
				pos = pos->sons[index];
			}else{
				for(int j = 0; j < 26; j++){
					if(pos->sons[j] && searchReg(key, pos->sons[j], i+1))
						return true;
				}
				return false;
			}
		}
		return pos->isNode;
	}

private:
    TrieNode* root;
};

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
 		   t.insert(word);    
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return t.searchReg(word);
    }
private:
	Trie t;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


int main(int argc, char** argv)
{
	WordDictionary wordDictionary;
	wordDictionary.addWord("bad");
	wordDictionary.addWord("dad");
	wordDictionary.addWord("mad");
	cout<<wordDictionary.search("pad")<<endl;
	cout<<wordDictionary.search("bad")<<endl;
	cout<<wordDictionary.search(".ad")<<endl;
	cout<<wordDictionary.search("b..")<<endl;
	return 0;

}
