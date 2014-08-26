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
	ListNode* partition(ListNode* s, ListNode* e){
		ListNode* pos = s, *last_less = s;
		int temp;
		while(pos->next != e->next){
			if(s->val > pos->next->val){
				if(last_less != pos){
					temp = last_less->next->val;
					last_less->next->val = pos->next->val;
					pos->next->val = temp;
				}
				last_less = last_less->next;
			}
			pos = pos->next;
		}
		temp = s->val;
		s->val = last_less->val;
		last_less->val = temp;
		
		return s;
	}
	
	ListNode* quicksort(ListNode* s, ListNode* e){
		if(s == e) return s;
		ListNode* part = partition(s, e);
		quicksort(s,part);
		if(part->next != NULL)
			quicksort(part->next, e);
		return s;
	}

	ListNode* mergesort(ListNode* s, ListNode* e, int n){
		if(n == 1) return s; 
		int len = n/2;
		ListNode* part = s;
		for(int i = 0; i < len - 1; i++){
			part = part->next;
		}		
	    ListNode* first = s;
		ListNode* second = part->next;
		part->next = NULL;
		e->next = NULL;
		first = mergesort(first, part, n/2);
		second = mergesort(second, e, n - n/2);
		ListNode header(0);
		//header.next = s;
	    ListNode* pos = &header;
		s = &header;
		while(1){
			if(first == NULL) break;
			if(second == NULL) break;
			if(first->val < second->val){
				pos->next = first;
				first = first->next;	
			}
			else{
				pos->next = second;
				second = second->next;
			}
			pos = pos->next;
		}
		if(first == NULL && second != NULL){
				pos->next = second;
		}
		if(first != NULL && second == NULL){
				pos->next = first;
		}
		return s->next;	
	}

	ListNode *sortList(ListNode *head) {
		if(head == NULL) return NULL;
		ListNode* pos, *tail;
		pos = head;
		int n = 1;
		while(pos->next != NULL){
			pos = pos->next;
			n++;
		}
		tail = pos;
		//return quicksort(head, tail);
		return mergesort(head, tail,n);
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
    head = sl.sortList(head);
	#ifdef DEBUG
	print(head);	
	#endif
	free(data);
	return 0;

}
