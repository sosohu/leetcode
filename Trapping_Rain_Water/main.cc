#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {

public:

	int trap_1st(int A[], int n) {
		vector<int> left(n, 0);
		vector<int> right(n, 0);

		for(int i = 1; i < n; i++){
			if(A[i] < A[i-1])
				left[i] = A[i-1] > left[i-1]? A[i-1] : left[i-1];
			else{
				if(A[i] > left[i-1])	left[i] = 0;
				else	left[i] = left[i-1];
			}
		}

		for(int i = n - 2; i >= 0; i--){
			if(A[i] < A[i+1])
				right[i] = A[i+1] > right[i+1]? A[i+1] : right[i+1];
			else{
				if(A[i] > right[i+1])	right[i] = 0;
				else	right[i] = right[i+1];
			}
		}

		int sum = 0;
		int min;
		for(int i = 0; i < n; i++){
			min = left[i] < right[i]? left[i]:right[i];
			if(min)
				sum = sum + min - A[i];
		}
		return sum;
    }
	
	/*每次元素小于等于栈顶元素时压栈，大于时候退栈处理*/
	int trap(vector<int>& height) {
		if(height.size() <= 1)	return 0;
		stack<pair<int,int> > s;
		s.push(make_pair(height[0], 0));
		int sum = 0;
		pair<int,int> cur;
		for(int i = 1; i < height.size(); i++){
			while(height[i] > s.top().first){
				cur = s.top();
				s.pop();
				if(!s.empty())	
					sum += (min(height[i], s.top().first) - cur.first) 
							* (i - s.top().second - 1);
				else	break;
			}
			s.push(make_pair(height[i], i));
		}
		return sum;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {4,2,0,3,2,5};
	vector<int> data(begin(A), end(A));

	int ret = sl.trap(data);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
