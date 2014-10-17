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

	vector<int> searchRange(int A[], int n, int target) {
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

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {6,6,6,6,6};

	vector<int> ret = sl.searchRange(A, 5, 6);
	
	cout<<"Result  :("<<ret[0]<<" "<<ret[1]<<")"<<endl;

	return 0;

}
