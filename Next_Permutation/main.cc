#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

	class mysort{
		public:
			bool operator()(int i, int j){
				return i < j;
			}
	} mysort;

public:

	void nextPermutation(vector<int> &num) {
		int n = num.size();
		int pos = n - 1;
		for(; pos > 0; pos--){
			if(num[pos] > num[pos-1])
				break;
		}
		if(pos == 0){
			sort(num.begin(), num.end(), mysort);
			return;
		}
		int last = num[pos-1];
		int end = pos;
		for(; end < n; end++)
			if(num[end] <= last)
				break;
		end--;
		num[pos-1] = num[end];
		num[end] = last;
		sort(num.begin() + pos, num.end(), mysort);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {1,5,1,1};
	vector<int> data(4, 0);
	for(int i = 0; i < 4; i++)
		data[i] = A[i];
	
	sl.nextPermutation(data);

	for(int i = 0; i < 4; i++)
		cout<<data[i]<<" ";
	cout<<endl;

	return 0;

}
