#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;


class Solution {

public:

	struct bucket_node{
		int val;
		bucket_node* next;
	};

	int march_bucket(int val, int pos){
		return (val / ((int)pow(10,pos))) % 10;
	}

	void bucket_aux(bucket_node start[], bucket_node end[], int n, int pos){
		bucket_node new_start[10], new_end[10];
		for(int i = 0; i < 10; i++){
			new_start[i].next = 0;
			new_end[i].next = &new_start[i];
		}
		for(int i = 0; i < n; i++){
			bucket_node *head = &start[i], *cur;
			while(head->next){
				cur = head->next;
				head->next = cur->next;
				int id = march_bucket(cur->val, pos);
				(new_end[id].next)->next = cur;
				cur->next = 0;
				new_end[id].next = cur;
			}
		}
		for(int i = 0; i < 10; i++){
			start[i] = new_start[i];
			end[i] = new_end[i];
		}
	}

	void bucket_pre(vector<int> &A, bucket_node node[], int n, int w){
		bucket_node start[10], end[10];
		start[0].next = &node[0];
		end[0].next = &node[n-1];
		for(int i = 1; i < 10; i++){
			start[i].next = 0;
			end[i].next = &start[i];
		}
		for(int i = 0; i < w; i++)
			bucket_aux(start, end, 10, i);
		int pos = 0;
		for(int i = 0; i < 10; i++){
			bucket_node* cur = &start[i];
			while(cur->next){
				cur = cur->next;
				A[pos++] = cur->val;
			}
		}
	}

	int maximumGap(vector<int> &num) {
		int n = num.size();
		if(n <= 1)	return 0;
		bucket_node node[n];
		bucket_node* pre = &node[0]; ;
		pre->val = num[0];
		for(int i = 1; i < n; i++){
			node[i].val = num[i];
			pre->next = &node[i];
			pre= pre->next;
		}
		pre->next = 0;
		bucket_pre(num, node, n, 10);
		int gap = INT_MIN;
		for(int  i = 1; i < n; i++)
			if(gap < num[i] - num[i-1])
				gap = num[i] - num[i-1];
		return gap;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> num{5,1,3,7,9,19};
	
	cout<<sl.maximumGap(num)<<endl;

	return 0;

}
