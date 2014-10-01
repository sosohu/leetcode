#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <cassert>

#define DATASIZE 6

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
	cout<<root->val<<endl;	
	if(root->right){
		prePrint(root->right);
	}
}


class Solution {

public:

	bool recursion(TreeNode* root, int max, bool left, TreeNode*& ret){
		#ifdef DEBUG
		cout<<"val "<<root->val<<" max "<<max<<endl;
		#endif
		if(left && root->val > max){
			ret = root;
			return false;
		}
		if(!left && root->val < max){
			ret = root;
			return false;
		}
		TreeNode *myleft, *myright;
		bool isleft = true, isright = true;
		if(root->left)
			isleft = recursion(root->left, root->val, true, myleft);
		if(root->right)
			isright = recursion(root->right, root->val, false, myright);

		if(!isleft && !isright){
			assert(myleft);
			assert(myright);
			swap(myleft->val, myright->val);
			return true;	
		}
		if(!isleft){
			assert(myleft);
			if((left && myleft->val > max) || (!left && myleft->val < max)){
				ret = myleft;
				return false;
			}else{
				swap(root->val, myleft->val);
				return true;
			}
		}
		if(!isright){
			assert(myright);
			if((left && myright->val > max) || (!left && myright->val < max)){
				ret = myright;
				return false;
			}else{
				swap(root->val, myright->val);
				return true;
			}
		}
		return true;
	}

	inline void swap(int& lv, int& rv){
		lv = lv - rv;
		rv = lv + rv;
		lv = rv - lv;
	}

	void recoverTree(TreeNode* root) {
		if(root == NULL)	return ;
		bool left = true, right = true;
		TreeNode *retl, *retr;
		if(root->left){
			left = recursion(root->left, root->val, true, retl);
		}
		if(root->right){
			right = recursion(root->right, root->val, false, retr);
		}
		if(!left && !right){
			assert(retl);
			assert(retr);
			swap(retl->val, retr->val);
		}
		if(!left){
			assert(retl);
			swap(root->val, retl->val);
		}
		if(!right){
			assert(retr);
			swap(root->val, retr->val);
		}
		return;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	
	TreeNode* root = (TreeNode*)malloc(DATASIZE*sizeof(TreeNode));
	int data[] = {3,2,5,0,1,4};
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

	prePrint(root);
	
	sl.recoverTree(root);
	
	prePrint(root);
	

	return 0;

}
