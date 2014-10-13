#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	void merge(int A[], int m, int B[], int n) {
		for(int i = m-1; i >= 0; i--){
			A[i + n] = A[i];
		}
		int ia = n, ib = 0, pos = 0;

		while(ia < n+m && ib < n){
			if(A[ia] < B[ib]){
				A[pos] = A[ia];
				ia++;	
			}else{
				A[pos] = B[ib];
				ib++;
			}
			pos++;
		}
		if(ia == n+m){
			for(; ib < n; ib++, pos++)
				A[pos] = B[ib];
		}
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	
	int A[] = {1,2,2,5,7,9,0,0,0,0,0};
	int B[] = {1,2,3,4,6};

	sl.merge(A, 6, B, 5);

	for(int i = 0; i < 11; i++)
		cout<<A[i]<<endl;

	return 0;

}
