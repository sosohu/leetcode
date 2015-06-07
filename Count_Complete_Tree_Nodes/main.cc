#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:

	int countNodes(TreeNode* root) {
		int count = 0;
		if(!root)	return count;
		TreeNode *pos = root->left;
		int deepl = 0, deepr = 0;
		while(pos){
			deepl++;
			pos = pos->left;
		}
		pos = root->right;
		while(pos){
			deepr++;
			pos = pos->left;
		}
		if(deepl == deepr)
			return (1 << deepl) + countNodes(root->right);
		else
			return (1 << deepr) + countNodes(root->left);
	}

};

int main(int argc, char** argv)
{
	Solution sl;

	return 0;

}
