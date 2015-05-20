#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

	int removeElement_1st(int A[], int n, int elem) {
		int pos, last;
		last = 0;
		for(pos = 0; pos < n; pos++){
			if(A[pos] != elem){
				if(pos != last){
					A[last] = A[pos];
				}
				last++;
			}
		}
		return last;
    }

	int removeElement(vector<int>& nums, int val) {
		int pos = 0;
		for(int i = 0; i < nums.size(); i++){
			if(nums[i] != val)	nums[pos++] = nums[i];
		}
		nums.resize(pos);
		return pos;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {1,2,4, 5, 3, 4,2,4,1};
	vector<int> data(begin(A), end(A));

	int len = sl.removeElement(data, 4);
	
	cout<<len<<endl;
	for(int i = 0; i < data.size(); i++)
		cout<<data[i]<<" ";
	cout<<endl;

	return 0;

}
