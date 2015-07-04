#include <iostream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool trace(TreeNode *root, int k, int &nums, int &res){
		if(!root)	return false;
		int left = 0, right = 0;
		if(trace(root->left, k, left, res))	return true;
		if(left + 1 == k){
			res = root->val;
			return true;
		}
		bool ret = trace(root->right, k - left - 1, right, res);
		nums = left + 1 + right;
		return ret;
	}

    int kthSmallest(TreeNode* root, int k) {
    	int res = 0, nums = 0;
		trace(root, k, nums, res);
		return res;
    }
};

int main(int argc, char** argv)
{
	Solution sl;
	return 0;
}
