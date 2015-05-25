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

	void nextPermutation_1st(vector<int> &num) {
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

	void nextPermutation(vector<int> &num) {
		int pos = num.size() - 1;
		while(pos > 0 && num[pos - 1] >= num[pos])	pos--;
		if(pos != 0){
			int pre = pos - 1;
			auto index = lower_bound(num.begin() + pos, num.end(), num[pre], greater<int>());
			swap(num[pre], num[index - num.begin() - 1]);
		}
		reverse(num.begin() + pos, num.end());
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {1,5,2,1};
	vector<int> data(4, 0);
	for(int i = 0; i < 4; i++)
		data[i] = A[i];
	
	sl.nextPermutation(data);

	for(int i = 0; i < 4; i++)
		cout<<data[i]<<" ";
	cout<<endl;

	return 0;

}
