#include <iostream>
#include <stdlib.h>


using namespace std;

#define DATASIZE 8

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x ) : val(x), next(NULL) {}
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
	
	ListNode *deleteDuplicates(ListNode *head) {
		if(head == NULL)	return NULL;

		ListNode *pre, *pos, *newhead;
		newhead = new ListNode(0);
		newhead->next = head;
		pre = newhead;
		pos = pre->next->next;

		int val;
		while(pos){
			val = pre->next->val;
			while(pos && val == pos->val){
				pos = pos->next;
			}
			if(pre->next->next == pos)
				pre = pre->next;
			else{
				pre->next = pos;
			}
			if(pos)
				pos = pos->next;
		}			
		return newhead->next;
	}

};


int main(int argc, char** argv)
{
	Solution sl;
	ListNode* data = (ListNode*)malloc(sizeof(ListNode)*DATASIZE);
	int val[DATASIZE] = {1,2,3,3,3,5,10,10};
	ListNode* head, *pos; 
	pos = &data[0];
	head = pos;
	for(int i = 0; i < DATASIZE - 1  ; i++){
		pos->next = &data[i+1];
		pos->val = val[i];
		pos = pos->next;
	}		
	pos->next = NULL; 
	pos->val = val[DATASIZE - 1]; 
	#ifdef DEBUG
	print(head);	
	#endif
    head = sl.deleteDuplicates(head);
	#ifdef DEBUG
	print(head);	
	#endif
	free(data);
	return 0;

}
