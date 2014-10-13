#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#define DATASIZE 10

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

	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > data;
		vector<vector<TreeNode*> > tree;
		if(root == NULL)
			return data;
		vector<TreeNode*> vec;
		vec.push_back(root);
		tree.push_back(vec);

		bool hasnext = true;
		int i = 0;
		TreeNode* tmp;
		while(hasnext){
			vec.clear();
			for(int j = 0; j < tree[i].size(); j++){
				tmp = tree[i][j];
				if(tmp->left)
					vec.push_back(tmp->left);
				if(tmp->right)
					vec.push_back(tmp->right);
			}
			if(vec.size() != 0)
				tree.push_back(vec);
			else
				hasnext = false;
			i++;
		}
		for(int j = tree.size()-1; j >= 0; j--){
			vector<int> v;
			for(int k = 0; k < tree[j].size(); k++)
				v.push_back(tree[j][k]->val);
			data.push_back(v);
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

	vector<vector<int> > ret = sl.levelOrderBottom(root);

	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}

	return 0;

}
