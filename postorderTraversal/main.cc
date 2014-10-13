#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>

using namespace std;

#define DATASIZE 2


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:

	vector<int> DpostorderTraversal(TreeNode *root) {
		vector<int> data;
		if(root == NULL) return data;
		vector<int> tmp;
		if(root->left != NULL){
			tmp = DpostorderTraversal(root->left);
			data.insert(data.end(), tmp.begin(), tmp.end());
		}
		if(root->right != NULL){
			tmp = DpostorderTraversal(root->right);
			data.insert(data.end(), tmp.begin(), tmp.end());
		}
		data.push_back(root->val);
		return data;
	}
	
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> data;
		if(root == NULL) return data;
		std::stack<TreeNode*> s;
		std::stack<TreeNode*> mark;
		mark.push(NULL);
		s.push(root);
		TreeNode* pos;
		while(!s.empty()){
				pos = s.top();		
				while(pos->left != NULL && mark.top() != pos->left){ 
					if(pos->right != NULL && pos->right == mark.top())
						break;
					s.push(pos->left);
					pos = pos->left;
				}
				if(pos->right != NULL 
						&& mark.top() != pos->right){
					s.push(pos->right);
					pos = pos->right;
				}
				else{
					data.push_back(pos->val);
					mark.push(pos);
					s.pop();
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
	
    vector<int> data = sl.postorderTraversal(root);
    //vector<int> data = sl.DpostorderTraversal(root);
	
	for(std::vector<int>::iterator iter = data.begin(); iter != data.end(); iter++){
			cout<<*iter<<" ";
	}
	cout<<endl;

	free(root);
	return 0;

}
