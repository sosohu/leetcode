#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	int recursion(vector<int> &num, int start, int end){
		int len = end - start + 1;
		if(len == 1)	return num[start];
		if(len == 2){
			return num[start] < num[end]? num[start] : num[end];
		}
		int mid = (start + end) / 2;
		if(num[mid] == num[start]){
			while(start < end & num[start] == num[start+1]){
				start++;
			}
			if(num[mid] == num[end]){
				while(end > start & num[end] == num[end-1]){
					end--;
				}
			}
			return recursion(num, start, end);
		}
		if(num[mid] > num[start]){
			return recursion(num, mid, end);
		}else{
			return recursion(num, start, mid);
		}
	}

	int findMin_1st(vector<int> &num) {
		int size = num.size();
		if(size == 0)	return 0;
		if(size == 1)	return num[0];
		if(num[0] < num[size - 1])	return num[0];
		return recursion(num, 0, size - 1);
    }

	int binary_search(vector<int> &num, int begin, int end){
		if(begin >= end)	return num[end];
		if(num[begin] < num[end])	return num[begin];
		int mid = (begin + end) / 2;
		if(num[mid] > num[begin]){
			return binary_search(num, mid+1, end);
		}else if(num[mid] < num[begin]){
			return binary_search(num, begin, mid);
		}else{
			int pos = begin;
			while(pos < mid && num[pos] == num[mid])	pos++;
			if(pos == mid)	return binary_search(num, mid+1, end);
			else	return binary_search(num, begin + pos, mid);
		}
	}

	int findMin(vector<int> &num) {
		int n = num.size();
		return binary_search(num, 0, n-1);
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> num{4,5,6,7,8,9,4,4,4,4};
	int ret = sl.findMin(num);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
