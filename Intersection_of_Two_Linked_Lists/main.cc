#include <iostream>
#include <algorithm>

#define DATASIZE 8


using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {

public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if(!headA || !headB)	return NULL;
		int la = 1, lb = 1;
		ListNode *posA = headA, *posB = headB;
		while(posA->next || posB->next){
			if(posA->next){
				la++;
				posA = posA->next;
			}
			if(posB->next){
				lb++;
				posB = posB->next;
			}
		}
		if(posA != posB)	return NULL;
		if(lb > la){
			swap(headA, headB);
			swap(la, lb);
		}
		for(auto i = 0; i < la -lb; i++)
			headA = headA->next;
		while(headA != headB){
			headA = headA->next;
			headB = headB->next;
		}
		return headA;
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
	cout<<sl.getIntersectionNode(head, &data[5])->val<<endl;		

	return 0;

}
