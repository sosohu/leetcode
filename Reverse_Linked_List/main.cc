#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x ) : val(x), next(NULL) {}
};

class Solution {

public:

	ListNode* reverseList_R(ListNode* head) {
		if(!head)	return head;
		ListNode newhead(0);
		newhead.next = head;
		ListNode *pos = head, *cur;
		while(pos->next){
			cur = pos->next;
			pos->next = cur->next;
			cur->next = newhead.next;
			newhead.next = cur;
		}
		return newhead.next;
	}

	ListNode* reverseList(ListNode* head) {
		if(!head || !head->next)	return head;
		ListNode *cur = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return cur;
	}

};

int main(int argc, char** argv)
{
	Solution sl;

	return 0;

}
