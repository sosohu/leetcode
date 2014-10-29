#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	int maxArea(vector<int> &height) {
		int size = height.size();
		if(size <= 1)	return 0;
		int low = 0;
		int high = size - 1;
		int max = 0;
		int cur, edge;
		while(low < high){
			edge = height[low] < height[high] ? height[low] : height[high];
			cur = edge * (high - low);
			if(cur > max) max = cur;
			if(edge == height[low]){
				low++;
			}else{
				high--;
			}
		}
		return max;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> height{1,5,3,7,8,2,4,3};
	int ret = sl.maxArea(height);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
