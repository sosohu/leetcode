#include <iostream>
#include <stdlib.h>

using namespace std;

#define DATASIZE 8

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
	
	ListNode *insertionSortList(ListNode *head) {
		if(head == NULL) return NULL;
		ListNode  header(0);
		header.next = head;
		head = &header;
		ListNode* pos = &header;
		ListNode* com = &header;
		ListNode* tmp;
		while(pos->next != NULL){
			cout<<"insert "<<pos->next->val<<endl;
			while(com->next != pos->next){
				if(com->next->val > pos->next->val){
					tmp = pos->next;
					pos->next = pos->next->next;
					tmp->next = com->next;
					com->next = tmp;
					pos = tmp;
					break;
				}
				com = com->next;
			}
			pos = pos->next;
			com = &header;
		}
		return head->next;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	ListNode* data = (ListNode*)malloc(sizeof(ListNode)*DATASIZE);
	int val[DATASIZE] = {2,-3,3,1,4,5,10,3};
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
    head = sl.insertionSortList(head);
	#ifdef DEBUG
	print(head);	
	#endif
	free(data);
	return 0;

}









