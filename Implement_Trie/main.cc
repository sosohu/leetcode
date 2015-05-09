/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-05-09 15:32
 * Filename :        main.cc
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#include <iostream>
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

int main(int argc, char** argv)
{
	Trie t;
	t.insert("abaaa");
	t.insert("dbaaa");
	t.insert("abcaa");
	cout<<t.search("adadf")<<endl;
	cout<<t.search("dbaaa")<<endl;
	cout<<t.startsWith("ab")<<endl;

	return 0;

}
