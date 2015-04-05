#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	bool canJump_1st(int A[], int n) {
		if(n == 0)	return false;
		vector<bool> path(n, false);
		path[n-1] = true;
		int last_true = n - 1;
		for(int i = n - 2; i >= 0; i--){
			for(int j = last_true - i; j <= A[i] && i+j < n; j++){
				path[i] = path[i] || path[i+j];
				if(path[i]){
					last_true = i;
					break;
				}
			}
		}
		return path[0];
    }

	bool canJump(int A[], int n) {
		int pos = n - 1;
		while(pos > 0){
			int j = pos;
			while(--j >= 0)
				if(A[j] + j >= pos) break;
			pos = j;
		}
		return pos == 0;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {3,2,1,0,4};
	bool ret = sl.canJump(A, 5);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
