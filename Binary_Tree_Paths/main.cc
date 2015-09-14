#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		string path;
		dfs(root, res, path);
		return res;
    }

	string itoa(int a){
		stringstream ss;
		ss<<a;
		return ss.str();
	}

	void dfs(TreeNode *root, vector<string> &res, string &path){
		if(!root)	return;
		int sz = path.size();
		path = path + itoa(root->val);
		if(!root->left && !root->right){
			res.push_back(path);
		}else{
			path.push_back('-');
			path.push_back('>');
			dfs(root->left, res, path);
			dfs(root->right, res, path);
			path.pop_back();
			path.pop_back();
		}
		path.resize(sz);
	}
};

int main(int argc, char** argv)
{
	Solution sl;

	return 0;

}
