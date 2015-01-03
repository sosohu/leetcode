#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void prePrint(TreeNode* root){
	if(root == NULL)
		return;
	if(root->left){
		prePrint(root->left);
	}
	if(root->right){
		prePrint(root->right);
	}
	cout<<root->val<<endl;	
}

class Solution {

public:

	TreeNode* detail(vector<int> &inorder, vector<int> &preorder, int in_start, int in_end, int pre_start, int pre_end){
		if(in_start > in_end || pre_start > pre_end) return NULL;
		int val = preorder[pre_start];

		TreeNode* father = new TreeNode(val);
		TreeNode *left = NULL, *right = NULL;
		
		int in_pos = in_start, pre_pos = pre_start;
		for(; in_pos <= in_end; in_pos++, pre_pos++){
			if(val == inorder[in_pos])
				break;
		}

		left = detail(inorder, preorder, in_start, in_pos-1, pre_start+1, pre_pos);
		right = detail(inorder, preorder, in_pos+1, in_end, pre_pos+1, pre_end);

		father->left = left;
		father->right = right;

		return father;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int size = inorder.size();
		if(size == 0) return NULL;
		return detail(inorder, preorder, 0, size - 1, 0, size - 1);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> inorder, preorder;
	for(int i = 0; i < 5; i++)
		inorder.push_back(i);
	preorder.push_back(2);
	preorder.push_back(0);
	preorder.push_back(1);
	preorder.push_back(4);
	preorder.push_back(3);

    TreeNode* ret = sl.buildTree(preorder, inorder);
	
	prePrint(ret);

	return 0;

}
