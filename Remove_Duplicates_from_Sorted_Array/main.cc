#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

	int removeDuplicates_1st(int A[], int n) {
		if(n == 0)	return 0;
		int pos, last, last_one;
		last = 1;
		last_one = A[0];
		for(pos = 1; pos < n; pos++){
			if(A[pos] != last_one){
				last_one = A[pos];
				if(pos != last){
					A[last] = A[pos];
				}
				last++;
			}
		}
		return last;
    }

	int removeDuplicates(vector<int>& nums) {
		int pos = 0;
		for(int i = 0; i < nums.size(); i++){
			if(!(i < nums.size() - 1 && nums[i] == nums[i+1]))
				nums[pos++] = nums[i];
		}
		nums.resize(pos);
		return pos;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {1,1,3,3,3,4,6,6,7,7};
	vector<int> data(begin(A), end(A));

	int len = sl.removeDuplicates(data);

	cout<<len<<endl;
	for(int i = 0; i < data.size(); i++)
		cout<<data[i]<<" ";
	cout<<endl;

	return 0;

}
