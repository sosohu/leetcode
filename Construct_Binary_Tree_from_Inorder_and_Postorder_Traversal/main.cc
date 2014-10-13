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
	cout<<root->val<<endl;	
	if(root->left){
		prePrint(root->left);
	}
	if(root->right){
		prePrint(root->right);
	}
}

class Solution {

public:

	TreeNode* detail(vector<int> &inorder, vector<int> &postorder, int in_start, int in_end, int post_start, int post_end){
		if(in_start > in_end || post_start > post_end)
			return NULL;
		int val = postorder[post_end];
		TreeNode* father = new TreeNode(val);
		int in_pos = in_start, post_pos = post_start;
		for(; in_pos <= in_end; in_pos++, post_pos++){
			if(inorder[in_pos] == val)
				break;
		}
		TreeNode *left = NULL, *right = NULL;
		
		left = detail(inorder, postorder, in_start, in_pos - 1, post_start, post_pos - 1);
		right = detail(inorder, postorder, in_pos + 1, in_end, post_pos, post_end - 1);

		father->left = left;
		father->right = right;

		return father;
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int size = inorder.size();
		if(size == 0)
			return NULL;
		return detail(inorder, postorder, 0, size - 1, 0, size - 1);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> inorder, postorder;
	for(int i = 0; i < 5; i++)
		inorder.push_back(i);
	postorder.push_back(1);
	postorder.push_back(0);
	postorder.push_back(3);
	postorder.push_back(4);
	postorder.push_back(2);

    TreeNode* ret = sl.buildTree(inorder, postorder);
	
	prePrint(ret);

	return 0;

}
