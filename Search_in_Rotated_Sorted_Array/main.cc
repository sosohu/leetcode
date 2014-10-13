#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int binay_search(int A[], int low, int high, int target){
		int mid;
		cout<<low<<" "<<high<<endl;
		while(low <= high){
			mid = (low + high)/2;
			if(A[mid] == target) return mid;
			if(A[mid] > target)
				high = mid - 1;
			else
				low = mid + 1;
		}
		return -1;
	}

	int search(int A[], int n, int target) {
		int low = 0, high = n - 1;
		int mid;
		while(low <= high){
			if(A[low] < A[high]) return binay_search(A, low, high, target);
			mid = (low + high)/2;
			if(A[mid] == target) return mid;
			if(A[low] <= target){
				if(A[mid] > target) return binay_search(A, low, mid, target);
				else{
					if(A[mid] > A[low]) low = mid + 1;
					else	high = mid - 1;
				}	
			}else{
				if(A[mid] < target) return binay_search(A, mid, high, target);
				else{
					if(A[mid] >= A[low]) low = mid + 1;
					else	high = mid - 1;	
				}
			}
		}

		return -1;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {3,4,5,6,7,8,1,2};
    int ret = sl.search(A, 8, 2);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
