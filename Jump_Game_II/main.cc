#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	int jump(int A[], int n) {
		if(n == 0 ) return 0;
		vector<int> data(n, n);
		vector<int> up(n, 0);
		vector<int> down(n, 0);
		for(int i = 0; i < n; i++){
			up[i] = A[i];
			
		}
		down[0] = 0;
		data[n-1] = 0;
		int last_up = up[0];
		for(int i = 1; i < n; i++){
			down[i] = last_up;
			if(last_up < up[i])
				last_up = up[i];
			else
				last_up--;
		}
		for(int i = n - 2; i >= 0; i--){
			if(up[i] >= down[i]){
				for(int j = i + down[i]; j < n && j <= i + up[i]; j++){
					if(data[i] > 1 + data[j]){
						data[i] = 1 + data[j];
					}
				}
			}
		}
		return data[0];
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {1,2,3};
	int ret = sl.jump(A, 3);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
