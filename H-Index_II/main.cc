#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int hIndex(vector<int>& citations) {
	    if(citations.size() == 0)   return 0;
		int low = 0, high = citations.size();
		int mid;
		while(low <= high){
			mid = (low + high) / 2;
			if(isOk(citations, mid)){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}
		return low - 1;
    }

	int isOk(vector<int> &citations, int mid){
		auto iter = lower_bound(citations.begin(), citations.end(), mid);
		int count = citations.end() - iter;
		return count >= mid;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> data{1, 3, 4, 5};
	cout<<sl.hIndex(data)<<endl;

	return 0;

}
