#include <iostream>
#include <string>
#include <stdlib.h>

#define DATASIZE 10

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {

public:
	
	int maxDepth(TreeNode *root) {
		if(root == NULL)
			return 0;
		if(root->left == NULL && root->right == NULL)
			return 1;

		int left = 0, right = 0;
		int deepth ;

		if(root->left)
			left = maxDepth(root->left);
		if(root->right)
			right = maxDepth(root->right);
		deepth = left;
		if(!root->left)
			deepth = right;
		else{
			 if(root->right)
				deepth = left > right? left : right;
		}
		deepth++;
		return deepth;		
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
	
	int ret = sl.maxDepth(root);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
