#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	bool search(int A[], int n, int target) {
		int low = 0, high = n - 1;
		int mid;
		while(low <= high){
			mid = (low + high)/2;
			if(A[mid] == target || A[low] == target || A[high] == target) return true;
			if(A[mid] == A[low] || A[mid] == A[high]){
				while(A[mid] == A[low]){
					low++;
				}
				while(A[mid] == A[high]){
					high--;
				}
				continue;
			}
			if(A[low] < A[mid]){
				if(A[low] < target && target < A[mid])
					high = mid - 1;
				else
					low = mid + 1;
			}else{
				if(A[mid] < target && target < A[high])
					low = mid + 1;
				else
					high = mid - 1;
			}
		}

		return false;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {1,1,3,1};
    bool ret = sl.search(A, 4, 3);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
