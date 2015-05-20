#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

	int removeDuplicates_1st(int A[], int n) {
		if(n <= 1) return n;
		int pre = 0, pos = 1, len = 0;	

		for(; pos < n; pos++){
			if(len != pre)
				A[len] = A[pre];
			len++;
			int l = 0;
			while(pos < n && A[pre] == A[pos]){
				pos++;
				l++;
			}
			if(l > 0){
				if(len != pos - 1)
					A[len] = A[pos - 1];
				len++;
			}
			if(pos == n - 1){
				if(len != pos)
					A[len] = A[pos];
				len++;	
			}
			pre = pos;
		}
		return len;
    }

	int removeDuplicates(vector<int>& nums) {
		int pos = 0;
		for(int i = 0; i < nums.size(); i++){
			nums[pos++] = nums[i];
			if(i < nums.size() - 1 && nums[i] == nums[i+1]){
				while(i < nums.size() - 1 && nums[i] == nums[i+1])
					i++;
				nums[pos++] = nums[i];
			}
		}
		nums.resize(pos);
		return pos;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {1,1,1,2,2,3,3};
	vector<int> data(begin(A), end(A));
	int ret = sl.removeDuplicates(data);
	
	for(int i = 0; i < data.size(); i++)
		cout<<data[i]<<" ";
	cout<<endl;
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
