#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int binay_search_1st(int A[], int low, int high, int target){
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

	int search_1st(int A[], int n, int target) {
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

	int binay_search(int A[], int begin, int end, int target){
		if(begin > end)	return -1;
		int mid = (begin + end) / 2;
		if(A[mid] == target)	return mid;
		if(A[mid] < target)	return binay_search(A, mid+1, end, target);
		else	return binay_search(A, begin, mid-1, target);
	}

	int search_aux(int A[], int begin, int end, int target){
		if(begin > end)	return -1;
		if(begin == end)	return A[begin] == target? begin : -1;
		if(A[end] > A[begin])	return binay_search(A, begin, end, target);
		int mid = (begin + end) / 2;
		if(target == A[mid])	return mid;
		if(A[mid] > A[begin]){
			if(target < A[mid] && target >= A[begin])
				return binay_search(A, begin, mid-1, target);
			return search_aux(A, mid+1, end, target);
		}else if(A[mid] == A[begin]){
			return A[end] == target? end : -1;
		}else{
			if(target > A[mid] && target <= A[end])
				return binay_search(A, mid+1, end, target);
			return search_aux(A, begin, mid-1, target);
		}
	}

	int search(int A[], int n, int target) {
		return search_aux(A, 0, n-1, target);
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {216,221,222,225,228,231,234,244,245,246,249,251,259,262,264,265,268,271,276,277,278,281,282,286,289,294,295,296,298,299,0,4,9,10,13,18,23,25,26,33,34,38,39,42,43,45,48,49,51,52,53,55,58,60,61,62,63,65,66,70,72,74,78,79,82,85,89,90,91,95,104,109,112,113,117,118,120,122,123,126,127,128,133,134,138,140,142,144,147,148,149,152,156,164,165,168,169,174,177,185,191,192,193,194,195,197,204,211,215};
	int n = sizeof(A) / sizeof(int);
    int ret = sl.search(A, n, 0);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
