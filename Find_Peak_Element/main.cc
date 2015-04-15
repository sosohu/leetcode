#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	bool isPeak(const vector<int> &num, int pos){
		return pos == 0?  num[pos] > num[pos+1] : num[pos] > num[pos-1];
	}

	int binary_sarch(const vector<int> &num, int begin, int end){
		if(begin >= end)	return end;
		int  mid = (begin + end) / 2;
		if(num[mid] > num[mid-1] && num[mid] > num[mid+1])
			return mid;
		if(num[mid] >= num[begin] && num[mid] >= num[end]){
			if(num[mid] < num[mid-1])
				return binary_sarch(num, begin, mid-1);
			return binary_sarch(num, mid+1, end);
		}
		if(num[mid] < num[begin])
			return binary_sarch(num, begin, mid-1);
		else
			return binary_sarch(num, mid+1, end);
			
	}

	int findPeakElement(const vector<int> &num) {
		int n = num.size();
		if(n <= 1)	return n-1;	
		if(isPeak(num, 0))	return 0;
		if(isPeak(num, n-1))	return n - 1;
		return binary_sarch(num, 1, n-2);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> num{1,2,3,1};

	cout<<sl.findPeakElement(num)<<endl;

	return 0;

}
