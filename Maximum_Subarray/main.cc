#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	int maxSubArray_1st(int A[], int n) {
		if(n == 1)	return A[0];

		int continus = A[0], inter = A[0];

		for(int i = 1; i < n; i++){
			if(A[i] >= 0){
				if(continus > 0)
					continus = continus + A[i];
				else
					continus = A[i];
			}else{
				if(continus > 0)
					continus = continus + A[i];
				else
					continus = A[i];
			}
			if(inter < continus)
				inter = continus;
		}
		return inter;
    }

	int maxSubArray(int A[], int n) {
		if(n <= 0)	return 0;
		int maxCon = A[0];
		vector<int> con(n, A[0]);
		for(int i = 1; i < n; i++){
			con[i] = max(A[i], con[i-1] + A[i]);
			if(maxCon < con[i])	maxCon = con[i];
		}
		return maxCon;
	}
};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    int ret = sl.maxSubArray(A, 9);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
