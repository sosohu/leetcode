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

	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if(l1 == NULL)	return l2;
		if(l2 == NULL)	return l1;

		ListNode *head, *pos, *pos1 = l1, *pos2 = l2;
		if(l1->val < l2->val){
			head = l1;
			pos1 = pos1->next;
		}
		else{
			head = pos2;
			pos2 = pos2->next;
		}
		pos = head;
		while(pos1 != NULL && pos2 != NULL){
			if(pos1->val < pos2->val){
				pos->next = pos1;
				pos1 = pos1->next;
			}else{
				pos->next = pos2;
				pos2 = pos2->next;
			}
			pos = pos->next;
			pos->next = NULL;
		}
		if(pos1){
			pos->next = pos1;
		}
		if(pos2){
			pos->next = pos2;
		}
		return head;
    }


};


int main(int argc, char** argv)
{
	Solution sl;
	ListNode* data = (ListNode*)malloc(sizeof(ListNode)*2*(DATASIZE+1));
	int val[2*DATASIZE+2] = {1,2,2,5,7,9,10,11,   1,3,5,7,9,10,15,19,20,22};
	ListNode *head1, *head2, *pos; 
	pos = &data[0];
	head1 = pos;
	for(int i = 0; i < DATASIZE - 1  ; i++){
		pos->next = &data[i+1];
		pos->val = val[i];
		pos = pos->next;
	}		
	pos->next = NULL; 
	pos->val = val[DATASIZE - 1]; 

	pos = &data[DATASIZE];
	head2 = pos;
	for(int i = DATASIZE; i < 2*DATASIZE + 1  ; i++){
		pos->next = &data[i+1];
		pos->val = val[i];
		pos = pos->next;
	}		
	pos->next = NULL; 
	pos->val = val[2*DATASIZE + 1]; 

	#ifdef DEBUG
	print(head1);	
	print(head2);	
	#endif
    ListNode* head = sl.mergeTwoLists(head1, head2);
	#ifdef DEBUG
	print(head);	
	#endif
	free(data);
	return 0;

}
