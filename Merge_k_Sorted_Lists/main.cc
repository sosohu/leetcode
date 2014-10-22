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

public:
	
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

};

int main(int argc, char** argv)
{
	Solution sl;
	ListNode* data = (ListNode*)malloc(sizeof(ListNode)*DATASIZE);
	//int val[DATASIZE] = {-6,-3,3,1,4,5,10,3};
	int val[DATASIZE] = {1,2,3,4,5,1,3,8,9,3,4,7,8};
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
