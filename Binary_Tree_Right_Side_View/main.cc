#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x = 0) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:

 	vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		if(!root)	return result;
		queue<TreeNode*> cur, next;
		cur.push(root);
		TreeNode* pos;
		while(!cur.empty()){
			pos = cur.front();
			cur.pop();
			if(pos->left)	next.push(pos->left);
			if(pos->right)	next.push(pos->right);
			if(cur.empty()){
				result.push_back(pos->val);
				next.swap(cur);
			}
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	TreeNode data[5];
	for(int i = 0; i < 5; i++)
		data[i].val = i+1;
	data[0].left = &data[1];
	data[0].right = &data[2];
	data[1].right = &data[4];
	data[2].right = &data[3];
	vector<int> ret = sl.rightSideView(&data[0]);
	for(int i = 0; i < ret.size(); i++)
		cout<<ret[i]<<endl;

	return 0;

}
