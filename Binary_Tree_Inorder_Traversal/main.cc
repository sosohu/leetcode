#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stack>

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
	
	//recursion
	vector<int> recursion(TreeNode* root){
		vector<int> data;
		if(root == NULL){
			return data;
		}

		if(root->left){
			data = recursion(root->left);
		}
		data.push_back(root->val);
		if(root->right){
			vector<int> tmp = recursion(root->right);
			data.insert(data.end(), tmp.begin(), tmp.end());
		}
		return data;
	}

	// iteration
	vector<int> iteration(TreeNode* root){
		vector<int> data;
		if(root == NULL) return data;

		stack<TreeNode*> s;
		s.push(root);
		TreeNode* pos = root->left;
		while(pos){
			s.push(pos);
			pos = pos->left;
		}

		while(!s.empty()){
			pos = s.top();
			s.pop();
			data.push_back(pos->val);
			if(pos->right){
				s.push(pos->right);
				pos = pos->right;
				pos = pos->left;
				while(pos){
					s.push(pos);
					pos=pos->left;
				}
			}
		}
		return data;
	}

	// second time coding
	vector<int> InOrderTraversal(TreeNode* root){
		vector<int> data;
		if(!root)   return data;
		stack<TreeNode*> s;
		TreeNode *pos = root;
		s.push(pos);
		while(pos->left){
			pos = pos->left;
			s.push(pos);
		}   
		while(!s.empty()){
			pos = s.top();
			s.pop();
			data.push_back(pos->val);
			if(pos->right){
				pos = pos->right;
				s.push(pos);
				while(pos->left){
					pos = pos->left;
					s.push(pos);
				}
			}
		}
		return data;
	}

	
	vector<int> inorderTraversal(TreeNode *root) {
		//return recursion(root);
		//return iteration(root);
		return InOrderTraversal(root);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	
	TreeNode* root = (TreeNode*)malloc(DATASIZE*sizeof(TreeNode));
	int data[] = {0,1,1,2,1,2,2};
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
	
	vector<int> ret = sl.inorderTraversal(root);
	
	for(int i = 0; i < ret.size(); i++)
		cout<<ret[i]<<" ";
	cout<<endl;

	return 0;

}
