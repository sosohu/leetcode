#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;


class Solution {

public:

	void bucket_sort(vector<int> &num, int pos){
		if(pos == 0)	return;
		vector<vector<int> > buckets(10, vector<int>());
		int div = pow(10, pos-1);
		for(auto i = 0; i < num.size(); i++){
			int id =  (num[i] / div) % 10;
			buckets[id].push_back(num[i]);
		}
		bucket_sort(buckets[0], pos-1);
		for(auto i = 1; i < 10; i++){
			bucket_sort(buckets[i], pos-1);
			buckets[0].insert(buckets[0].end(), buckets[i].begin(), buckets[i].end());
		}
		swap(num, buckets[0]);
	}

	int maximumGap(vector<int> &num) {
		if(num.size() < 2)	return 0;
		bucket_sort(num, 10);
		int max = INT_MIN;
		for(int i = 1; i < num.size(); i++){
			max = num[i] - num[i-1] > max? num[i] - num[i-1] : max;
		}
		return max;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> num{5,1,3,7,9,10};
	
	cout<<sl.maximumGap(num)<<endl;

	return 0;

}
