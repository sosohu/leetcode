#include <iostream>
#include <string>
#include <vector>

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

	vector<int> searchRange_1st(int A[], int n, int target) {
		vector<int> data(2, -1);
		int pos =  binarysearch(A, 0, n - 1, target);
		if(pos == n){
			return data;
		}
		int down = pos;
		int up = pos;
		if(down > 0 && A[down-1] == target){
			do{
				pos = down - 1;
				down = binarysearch(A, 0, pos, target);
			} while(down > 0 && A[down-1] == target);
		}
		if(up < n-1 && A[up+1] == target){
			do{
				pos = up + 1;
				up = binarysearch(A, pos, n - 1, target);
			} while(up < n - 1 && A[up+1] == target);
		}

		data[0] = down;
		data[1] = up;
		return data;
    }

	int binary_sarch(int A[], int begin, int end, int target){
		if(begin > end)	return -1;
		int mid = (begin + end) / 2;
		if(A[mid] == target)	return mid;
		if(A[mid] > target)	return binary_sarch(A, begin, mid-1, target);
		return binary_sarch(A, mid+1, end, target);
	}

	int binary_sarchNo(int A[], int begin, int end, int target, bool left){
		if(begin > end)	return left? begin : end;
		int mid = (begin + end) / 2;
		int new_begin, new_end;
		if(A[mid] == target){
			new_begin = left? begin : mid + 1;
			new_end = left? mid - 1 : end;
		}else if(A[mid] > target){
			return binary_sarchNo(A, begin, mid - 1, target, left);
		}else{
			return binary_sarchNo(A, mid+1, end, target, left);
		}
		return binary_sarchNo(A, new_begin, new_end, target, left);
	}

	vector<int> searchRange(int A[], int n, int target) {
		vector<int> result{-1, -1};
		int pos = binary_sarch(A, 0, n-1, target);
		if(pos != -1){
			result[0] = pos == 0? 0 : binary_sarchNo(A, 0, pos, target, true);
			result[1] = pos == n-1? n-1 : binary_sarchNo(A, pos, n-1, target, false);
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {6,6,6,6,6};

	vector<int> ret = sl.searchRange(A, 5, 6);
	
	cout<<"Result  :("<<ret[0]<<" "<<ret[1]<<")"<<endl;

	return 0;

}
