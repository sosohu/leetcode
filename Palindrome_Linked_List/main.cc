#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

public:
	bool recursion(ListNode *head, ListNode *&pCur, int pos, int n){
		if(n % 2 && pos == n / 2 + 1){
			pCur = head->next;
			return true;
		}else if(n % 2 == 0 && pos == n / 2){
			pCur = head->next->next;
			return head->val == head->next->val;
		}else{
			if(recursion(head->next, pCur, pos+1, n)){
				if(head->val == pCur->val){
					pCur = pCur->next;
					return true;
				}
			}
			return false;
		}
	}

    bool isPalindrome(ListNode* head) {
		int n = 0;
		ListNode *pCur = head;
		while(pCur){
			pCur = pCur->next;
			n++;
		}
		return n == 0? true : recursion(head, pCur, 1, n);
    }

};

int main(int argc, char** argv)
{
	Solution sl;

	return 0;

}
