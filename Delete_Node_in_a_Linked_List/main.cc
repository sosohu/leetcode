#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL || node->next == NULL)    return;
        node->val = node->next->val;
        ListNode *next = node->next;
        node->next = node->next->next;
        delete next;
    }
};

int main(int argc, char** argv)
{
	Solution sl;

	return 0;
}
