#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

#define DATASIZE 13

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode* data)
{
	ListNode* pos = data;
	cout<<"Result  :"<<endl;
	while(pos != NULL)
	{
		cout<<"val: "<<pos->val<<endl;
		pos = pos->next;
	}
}

class Solution {

	class MinHeap{
		
		struct HeapNode{
			HeapNode *left, *right;
			ListNode *node;
			HeapNode(): node(NULL), left(NULL), right(NULL){}
		};

		public:
			MinHeap(int size, vector<ListNode*> rhs) : data(size, HeapNode()){
				for(int i = 0; i < size; i++)
					data[i].node = rhs[i];

				for(int i = 0; i < size; i++){
					if(2*i+1 < size){
						data[i].left = &data[2*i+1];
					}
					if(2*i+2 < size){
						data[i].right = &data[2*i+2];
					}
				}
				adjust_init(&data[0]);
			}

			~MinHeap(){}

			void adjust(HeapNode *root){
				if(!root)	return;
				ListNode *tmp;
				int left = root->node->val;
				int right = root->node->val;
				if(root->left)
					left = root->left->node->val;
				if(root->right)
					right = root->right->node->val;
				if(root->node->val <= left && root->node->val <= right)	return;
				if(left < right){
					tmp = root->node;
					root->node = root->left->node;
					root->left->node = tmp;
					adjust(root->left);
				}else{
					tmp = root->node;
					root->node = root->right->node;
					root->right->node = tmp;
					adjust(root->right);
				}
			}

			void adjust_init(HeapNode *root){
				ListNode *tmp;
				if(root->left){
					adjust_init(root->left);
					if(root->node->val > root->left->node->val){
						tmp = root->node;
						root->node = root->left->node;
						root->left->node = tmp;
					}
					adjust(root->left);
				}
				if(root->right){
					adjust_init(root->right);
					if(root->node->val > root->right->node->val){
						tmp = root->node;
						root->node = root->right->node;
						root->right->node = tmp;
					}
					adjust(root->right);
				}
			}

			ListNode* get_min(){
				return data[0].node;
			}

			HeapNode* get_root(){
				return &data[0];
			}

			void change_root(ListNode *value){
				data[0].node = value;
				adjust(&data[0]);
			}

			void print(HeapNode* root){
				if(root){
					cout<<root->node->val<<endl;
					print(root->left);
					print(root->right);
				}
			}
		
		private:
			vector<HeapNode> data;	
	};

	static const int  MAX_VALUE = ((1<<30) - 1 + (1<<30)) ;	

public:

	// O(n*lgk)
	ListNode *mergeKLists(vector<ListNode*> &lists) {
		int size = lists.size();
		if(size == 0)	return NULL;
		if(size == 1)	return lists[0];
		ListNode *margin = new ListNode(MAX_VALUE);
		for(int i = 0; i < size; i++){
			if(lists[i] == NULL)
				lists[i] = margin;
		}
		MinHeap minheadp(size, lists);
		int count = 0;
		ListNode *newhead = new ListNode(0);
		ListNode *last = newhead, *cur;
		cur = minheadp.get_min();
		while(cur->val != MAX_VALUE){
			//minheadp.print(minheadp.get_root());
			last->next = cur;
			last = last->next;
			if(cur->next == NULL){
				cur->next = margin;
			}
			minheadp.change_root(cur->next);
			cur = minheadp.get_min();
		}	
		last->next = NULL;
		return newhead->next;
	}
	
	// O(n^2)
	/*
	ListNode *mergeKLists(vector<ListNode*> &lists) {
		int size = lists.size();
		if(size == 0)	return NULL;
		if(size == 1)	return lists[0];
		ListNode *p1, *p2, *last, *tmp;
		ListNode *newhead = new ListNode(0);
		newhead->next = lists[0];
		for(int i = 1; i < size; i++){
			last = newhead;
			p1 = newhead->next;
			p2 = lists[i];
			while(p1 && p2){
				if(p1->val < p2->val){
					p1 = p1->next;
				}else{
					tmp = p2->next;
					last->next = p2;
					p2->next = p1;
					p2 = tmp;
				}
				last = last->next;
			}
			if(!p1){
				last->next = p2;
			}
		}
		return newhead->next;
	}
	*/
};

int main(int argc, char** argv)
{
	Solution sl;
	ListNode* data = (ListNode*)malloc(sizeof(ListNode)*DATASIZE);
	//int val[DATASIZE] = {-6,-3,3,1,4,5,10,3};
	int val[DATASIZE] = {1,3,5,7,9,2,4,6,8,10,14,17,18};
	ListNode* head, *pos; 
	pos = &data[0];
	for(int i = 0; i < DATASIZE - 1  ; i++){
		pos->next = &data[i+1];
		pos->val = val[i];
		pos = pos->next;
	}		
	pos->next = NULL; 
	pos->val = val[DATASIZE - 1]; 
	pos = &data[4];
	pos->next = NULL; 
	pos = &data[8];
	pos->next = NULL; 
	#ifdef DEBUG
	//print(head);	
	#endif
	vector<ListNode*> vec(3, NULL);
	vec[0] = &data[0];
	vec[1] = &data[5];
	vec[2] = &data[9];
    head = sl.mergeKLists(vec);
	#ifdef DEBUG
	print(head);	
	#endif
	free(data);
	return 0;

}
