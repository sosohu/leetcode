#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int partition(int A[], int start, int end){
		int pos = start;
		int last_pos = start;
		int tmp;
		while(pos <= end){
			if(A[start] <= A[pos]){
				if(last_pos != pos){
					tmp = A[pos];
					A[pos] = A[last_pos];
					A[last_pos] = tmp;
				}
				last_pos++;
			}
			pos++;
		}
		tmp = A[start];
		A[start] = A[last_pos - 1];
		A[last_pos - 1] = tmp;
		return last_pos - 1;
	}

	int recursion(int A[], int start, int end, int up){
		if(start == end){
			if(A[start] == up + 1)	return up + 2;
			else	return up + 1;	
		}

		if(start > end){
			return up + 1;
		}
		
		int part = partition(A, start, end);

		#ifdef DEBUG
		cout<<part<<endl;
		for(int i = start; i <= end; i++)
			cout<<A[i]<<" ";
		cout<<endl;
		#endif
		
		if(A[part] - up > end - part + 1){
			return recursion(A, part+1,end, up);
		}else{
			return recursion(A, start, part-1, A[part]);
		}	
		
	}

	void preprocess(int A[], int& n){
		int last = 0;
		int tmp;
		for(int i = 0; i < n; i++){
			if(A[i] > 0){
				if(i != last){
					tmp = A[last];
					A[last] = A[i];
					A[i] = tmp;
				}
				last++;
			}
		}
		n = last;
	}

	int firstMissingPositive(int A[], int n){
		preprocess(A, n);
		if(n == 0)	return 1;
		return recursion(A, 0, n-1, 0);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {1,1,4,1,4};
	int ret = sl.firstMissingPositive(A, 5);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
