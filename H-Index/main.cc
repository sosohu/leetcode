#include <iostream>
#include <vector>

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
		int count = 0;
		for(int i = 0; i < citations.size(); i++){
			if(citations[i] >= mid){
				count++;
			}
		}
		return count >= mid;
	}
};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> data{0, 0};
	cout<<sl.hIndex(data)<<endl;

	return 0;

}
