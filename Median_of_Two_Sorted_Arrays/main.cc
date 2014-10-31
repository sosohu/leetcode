#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int recursion(int A[], int sa, int ea, int B[], int sb, int eb, int k){
		if(sa == ea && sb == eb){
			if(k == 1){
				return A[sa] < B[sb] ? A[sa] : B[sb];
			}else{
				return A[sa] > B[sb] ? A[sa] : B[sb];
			}
		}
		if(sa > ea){
			return 	B[sb + k - 1];
		}
		if(sb > eb){
			return  A[sa + k - 1];
		}
		int ma = (sa + ea) / 2;
		int mb = (sb + eb) / 2;
		int la = ma - sa + 1;
		int lb = mb - sb + 1;
		if(la + lb == k){
			if(A[ma] == B[mb])	return A[ma];
			if(A[ma] > B[mb])	return recursion(A, sa, ma, B, mb+1, eb, k - lb);
			else				return recursion(A, ma+1, ea, B, sb, mb, k - la);
		}
		if(la + lb < k){
			if(A[ma] == B[mb])
				return recursion(A, ma+1, ea, B, mb+1, eb, k - la - lb);
			if(A[ma] > B[mb])
				return recursion(A, sa, ea, B, mb+1, eb, k - lb);
			else
				return recursion(A, ma+1, ea, B, sb, eb, k - la);
		}else{
			if(A[ma] == B[mb])
				return recursion(A, sa, ma, B, sb, mb, k);
			if(A[ma] > B[mb])
				return recursion(A, sa, ma-1, B, sb, eb, k);
			else
				return recursion(A, sa, ea, B, sb, mb-1, k);
		}	
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if(m == 0 && n == 0)	return 0;
		if(m == 0){
			if(n%2 == 0){
				return (B[n/2 - 1] + B[n/2]) / 2.0;
			}else{
				return B[n/2];
			}
		}
		if(n == 0){
			if(m%2 == 0){
				return (A[m/2 - 1] + A[m/2]) / 2.0;
			}else{
				return A[m/2];
			}
		}
		if((m+n) % 2 == 0){
			int pre = recursion(A, 0, m-1, B, 0, n-1, (m+n)/2);
			int next = recursion(A, 0, m-1, B, 0, n-1, (m+n)/2 + 1);
			#ifdef DEBUG
			cout<<pre<<" "<<next<<endl;
			#endif
			return (pre + next) / 2.0;
		}else{
			return recursion(A, 0, m-1, B, 0, n-1, (m+n)/2 + 1);
		}
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {3};
	int B[] = {1,2,4};

	double ret = sl.findMedianSortedArrays(A, 1, B, 3);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
