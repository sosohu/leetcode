#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	int trap(int A[], int n) {
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

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};

	int ret = sl.trap(A, 12);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
