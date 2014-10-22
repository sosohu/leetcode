#include <iostream>
#include <string>
#include <stdlib.h>

#define DATASIZE 10

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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

	TreeNode *detail(ListNode *head, ListNode*& tail, int n) {
		if(head == NULL)
			return NULL;
		if(n == 1){
			TreeNode* one = new TreeNode(head->val);
			tail = head->next;
			return one;
		}

		ListNode* mytail;
		TreeNode* left = detail(head, mytail, n/2);
		TreeNode* father = new TreeNode(mytail->val);
		mytail = mytail->next;
		TreeNode* right;
		if(n > 2)
			right = detail(mytail, tail, n - 1 - n/2);
		else{
			right = NULL;
			tail = mytail;
		}
		father->left = left;
		father->right = right;

		return father;
	}

	TreeNode *sortedListToBST(ListNode *head) {
		ListNode* tail = head, *pos = head;
		int n = 0;
		while(pos != NULL){
			pos = pos->next;
			n++;
		}
		return detail(head, tail, n);
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	
	ListNode* root = (ListNode*)malloc(DATASIZE*sizeof(ListNode));
	int count = 0;
	while(count < DATASIZE){
		root[count].val = count;
		root[count].next = &root[(count+1)%DATASIZE];
		count++;
	}	
	root[DATASIZE-1].next = NULL;
	
	TreeNode* ret = sl.sortedListToBST(root);
	
	prePrint(ret);

	return 0;

}