#include <iostream>
#include <vector>
#include <climits>

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

	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int pos = m + n - 1, i = m - 1, j = n - 1;
		while(pos >= 0){
			nums1[pos--] = (i < 0? INT_MIN : nums1[i]) < (j < 0? INT_MIN : nums2[j])? 
							nums2[j--] : nums1[i--];
		}
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	
	int A[] = {1,2,2,5,7,9,0,0,0,0,0};
	int B[] = {1,2,3,4,6};
	vector<int> dataA(begin(A), end(A));
	vector<int> dataB(begin(B), end(B));

	sl.merge(dataA, 6, dataB, 5);

	for(int i = 0; i < 11; i++)
		cout<<dataA[i]<<endl;

	return 0;

}
