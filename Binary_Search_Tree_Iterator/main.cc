/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-05-09 15:33
 * Filename :        main.cc
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
	TreeNode* root;
	stack<TreeNode*> path;
public:
    BSTIterator(TreeNode *root) : root(root){
		TreeNode* iter = root;
		while(iter){
			path.push(iter);
			iter = iter->left;
		}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		return !path.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = path.top();
		TreeNode *iter = cur->right;
		path.pop();
		while(iter){
			path.push(iter);
			iter = iter->left;
		}
		return cur->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, char** argv)
{
	TreeNode data[5];
	for(int i = 0; i < 5; i++)
		data[i].val = i;
	data[1].left = &data[0];
	data[1].right = &data[4];
	data[4].left = &data[2];
	data[2].right = &data[3];
	BSTIterator i = BSTIterator(&data[1]);
	while(i.hasNext())	cout<<i.next()<<endl;
	return 0;

}
