#include <iostream>
#include <string>
#include <stdlib.h>

#define DATASIZE 7

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {

public:

	bool hasPathSum(TreeNode *root, int sum) {
		if(root == NULL)
			return false;
		int val = root->val;
		sum = sum - val;
		if(sum == 0 && !root->left && !root->right)
			return true;

		bool left = false; 
		if(root->left){
			left = hasPathSum(root->left, sum);	
		}
		if(left)
			return true;
		if(root->right)
			return hasPathSum(root->right, sum);
		return false;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	
	TreeNode* root = (TreeNode*)malloc(DATASIZE*sizeof(TreeNode));
	int count = 0;
	while(count < DATASIZE){
		root[count].val = count;
		if(2*count + 1 < DATASIZE){
			root[count].left = &root[2*count + 1]; 
		}
		else{
			root[count].left = NULL; 
		}
		if(2*count + 2 < DATASIZE){
			root[count].right = &root[2*count + 2]; 
		}
		else{
			root[count].right = NULL; 
		}
		count++;
	}	
	
	bool ret = sl.hasPathSum(root, 7);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
