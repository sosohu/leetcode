#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int removeDuplicates(int A[], int n) {
		if(n <= 1) return n;
		int pre = 0, pos = 1, len = 0;	

		for(; pos < n; pos++){
			if(len != pre)
				A[len] = A[pre];
			len++;
			int l = 0;
			while(pos < n && A[pre] == A[pos]){
				pos++;
				l++;
			}
			if(l > 0){
				if(len != pos - 1)
					A[len] = A[pos - 1];
				len++;
			}
			if(pos == n - 1){
				if(len != pos)
					A[len] = A[pos];
				len++;	
			}
			pre = pos;
		}
		return len;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {1,1,1,2,2,3,3};
	int ret = sl.removeDuplicates(A, 7);
	
	for(int i = 0; i < ret; i++)
		cout<<A[i]<<" ";
	cout<<endl;
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
