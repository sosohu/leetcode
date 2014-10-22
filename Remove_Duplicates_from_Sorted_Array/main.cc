#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int removeDuplicates(int A[], int n) {
		if(n == 0)	return 0;
		int pos, last, last_one;
		last = 1;
		last_one = A[0];
		for(pos = 1; pos < n; pos++){
			if(A[pos] != last_one){
				last_one = A[pos];
				if(pos != last){
					A[last] = A[pos];
				}
				last++;
			}
		}
		return last;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {1,1,3,3,3,4,6,6,7,7};

	int len = sl.removeDuplicates(A, 10);

	cout<<len<<endl;
	for(int i = 0; i < len; i++)
		cout<<A[i]<<" ";
	cout<<endl;

	return 0;

}
