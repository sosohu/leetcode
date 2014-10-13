#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

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
	bool recursion(TreeNode* root, TreeNode*& last){
		bool left = true, right = true;
		if(root->left)
			left = recursion(root->left, last);	
		if(!left) return false;

		if(last && last->val >= root->val)
				return false;
		last = root;

		if(root->right)
			right = recursion(root->right, last);
		if(!right)	return false;

		return true;
	}

	bool isValidBST(TreeNode *root) {
		if(root == NULL)
			return true;

		TreeNode* last = NULL;
		return recursion(root, last);
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	
	TreeNode* root = (TreeNode*)malloc(DATASIZE*sizeof(TreeNode));
	int data[] = {3,1,5,0,2,4,6};
	int count = 0;
	while(count < DATASIZE){
		root[count].val = data[count];
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
	
	bool ret = sl.isValidBST(root);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
