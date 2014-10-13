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

	TreeNode* detail(vector<int>& num, int start, int end){
		if(start > end)
			return NULL;
		TreeNode* father, * left = NULL, * right = NULL;
		int mid = start + (end - start)/2;
		father = new TreeNode(num[mid]);
		left = detail(num, start, mid - 1);
		right = detail(num, mid+1,end);

		father->left = left;
		father->right = right;
		
		return father;
	}

	TreeNode *sortedArrayToBST(vector<int> &num) {	
		int size = num.size();
		if(size == 0)
			return NULL;
		return detail(num, 0, size - 1);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> data;
	for(int i = 0; i < 10; i++)
		data.push_back(i);
    TreeNode* ret = sl.sortedArrayToBST(data);
	
	prePrint(ret);

	return 0;

}
