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

	void detail(TreeNode* root, int& inside, int& outside){
		if(root == NULL){
			inside = 0;
			outside = 0;
			return;
		}
		int val = root->val;
		int left_inside, left_outside, right_inside, right_outside;
		detail(root->left, left_inside, left_outside);
		detail(root->right, right_inside, right_outside);

		if(left_outside < 0 && right_outside < 0){
			outside = val;
		}
		else{
			outside = left_outside > right_outside? left_outside : right_outside;
			outside = outside + val;
		}
		inside = val;
		if(left_outside > 0) inside = inside + left_outside;
		if(right_outside > 0) inside = inside + right_outside;

		if(inside < left_inside && left_inside != 0) inside = left_inside;
		if(inside < right_inside && right_inside != 0) inside = right_inside;
	}

	int maxPathSum(TreeNode *root) {
		int inside, outside;
		detail(root, inside, outside);
		return inside;	
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	TreeNode* root = (TreeNode*)malloc(DATASIZE*sizeof(TreeNode));
	int data[DATASIZE] = {-1,2,3,4,2,-6,-7};
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

    int ret = sl.maxPathSum(root);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
