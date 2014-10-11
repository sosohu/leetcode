#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	int jump(int A[], int n) {
		vector<int> data(n, n);
		data[n-1] = 0;
		int last = n - 1;
		for(int i = n - 2; i >= 0; i--){
			for(int j = last; j <= i + A[i] && j < n; j++){
				if(data[i] > 1 + data[j]){
					data[i] = 1 + data[j];
					last = i;
				}
			}
		}
		return data[0];
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {4,3,0,1,2,1};
	int ret = sl.jump(A, 6);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
