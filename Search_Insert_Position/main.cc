#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int binarysearch(int A[], int start, int end, int target){
		if(start > end)	return start;
		int mid = (start + end) / 2;
		if(A[mid] == target)	return mid;
		if(A[mid] < target)	return binarysearch(A, mid+1, end, target);
		else	return binarysearch(A, start, mid-1, target);
	}

	int searchInsert_1st(int A[], int n, int target) {
		
		return binarysearch(A, 0, n - 1, target);
		
    }

	int binary_search(int A[], int begin, int end, int target){
		if(begin > end){
			return begin;
		}
		int mid = (begin + end) / 2;
		if(A[mid] == target)	return mid;
		if(A[mid] > target)	return binary_search(A, begin, mid-1, target);
		return binary_search(A, mid+1, end, target);
	}

	int searchInsert(int A[], int n, int target) {
		return binary_search(A, 0, n-1, target);
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {1,3,6,7,7};

	int ret = sl.searchInsert(A, 5, 6);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
