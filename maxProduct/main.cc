#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int detail(int A[], int n, int& max_pos, int& max_neg) {
		if(n == 1){
			max_pos = A[0];
			max_neg = A[0];
			return A[0];
		}
		int pos, neg;
		int prefix = detail(A, n -1, pos, neg);

		int continues;
		if(A[n-1] == 0){
			continues = 0;
			max_pos = 0;
			max_neg = 0;
		}else{
			if(A[n-1] > 0){
				if(pos > 0){
					continues = pos * A[n-1];
				}else{
					continues = A[n-1];
				}
				max_pos = continues;
				if(neg != 0)
					max_neg = neg*A[n-1];
				else
					max_neg = A[n-1];
			}else{
				if(neg < 0){
					continues = neg*A[n-1];
					max_pos = continues;
					if(pos > 0)
						max_neg = pos*A[n-1];
					else
						max_neg = A[n-1];
				}else{
					if(neg == 0)
						continues = A[n-1];
					else
						continues = neg*A[n-1];
					max_neg = continues;
					max_pos = 0;
				}
			}
		}
		int ret = prefix;
		if(continues > prefix)
			ret = continues;	

		return ret;
	}

	int maxProduct(int A[], int n) {
		int pos, neg;
		return detail(A, n, pos, neg);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int data[6] = {-2,0,3,-2,-2, 5};
    int ret = sl.maxProduct(data,6);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
