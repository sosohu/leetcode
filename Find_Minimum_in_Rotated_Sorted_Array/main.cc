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
		if(num[mid] > num[start]){
			return recursion(num, mid, end);
		}else{
			return recursion(num, start, mid);
		}
	}

	int findMin(vector<int> &num) {
		int size = num.size();
		if(size == 0)	return 0;
		if(size == 1)	return num[0];
		if(num[0] < num[size - 1])	return num[0];
		return recursion(num, 0, size - 1);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> num{4,5,6,7,8,9};
	int ret = sl.findMin(num);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
