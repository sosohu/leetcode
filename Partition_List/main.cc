#include <iostream>
#include <stdlib.h>


using namespace std;

#define DATASIZE 3

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

	ListNode *partition(ListNode *head, int x) {
		if(head == NULL)	return NULL;
	
    	ListNode* newhead = new ListNode(0);
		newhead->next = head;
		ListNode *pos, *last, *tmp;
		pos = newhead;
		last = newhead;
		
		while(pos->next){
			if(pos->next->val < x){
				if(last != pos){
					tmp = pos->next;
					pos->next = tmp->next;
					tmp->next = last->next;
					last->next = tmp;
					last = last->next;
				}else{
					last = last->next;
					pos = pos->next;
				}
			}else{
				pos = pos->next;
			}
		}    
		return newhead->next;
    }
};


int main(int argc, char** argv)
{
	Solution sl;
	ListNode* data = (ListNode*)malloc(sizeof(ListNode)*DATASIZE);
	int val[DATASIZE] = {3,1,2};
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
    head = sl.partition(head, 3);
	#ifdef DEBUG
	print(head);	
	#endif
	free(data);
	return 0;

}
