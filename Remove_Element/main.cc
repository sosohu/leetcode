#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int removeElement(int A[], int n, int elem) {
		int pos, last;
		last = 0;
		for(pos = 0; pos < n; pos++){
			if(A[pos] != elem){
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
	int A[] = {1,2,4, 5, 3, 4,2,4,1};

	int len = sl.removeElement(A, 9, 4);
	
	cout<<len<<endl;
	for(int i = 0; i < len; i++)
		cout<<A[i]<<" ";
	cout<<endl;

	return 0;

}
