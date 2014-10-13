#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>

using namespace std;

#define DATASIZE 1


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:

	vector<int> DpreorderTraversal(TreeNode *root) {
		vector<int> data;
		if(root == NULL) return data;
		vector<int> tmp;
		data.push_back(root->val);
		if(root->left != NULL){
			tmp = DpreorderTraversal(root->left);
			data.insert(data.end(), tmp.begin(), tmp.end());
		}
		if(root->right != NULL){
			tmp = DpreorderTraversal(root->right);
			data.insert(data.end(), tmp.begin(), tmp.end());
		}
		return data;
	}
	
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> data;
		if(root == NULL) return data;
		std::stack<TreeNode*> s;
		s.push(root);
		TreeNode* pos;
		while(!s.empty()){
				pos = s.top();		
				data.push_back(pos->val);
				s.pop();
				if(pos->right != NULL){ 
					s.push(pos->right);
				}
				if(pos->left != NULL){ 
					s.push(pos->left);
				}
		}
		return data;	
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
	
    vector<int> data = sl.preorderTraversal(root);
    //vector<int> data = sl.DpreorderTraversal(root);
	
	for(std::vector<int>::iterator iter = data.begin(); iter != data.end(); iter++){
			cout<<*iter<<" ";
	}
	cout<<endl;

	free(root);
	return 0;

}
