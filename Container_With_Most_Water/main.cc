#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

	int maxArea_1st(vector<int> &height) {
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

	int maxArea(vector<int> &height) {
		int size = height.size();
		int water = 0;
		int left = 0, right = size - 1;
		while(left < right){
			water = max(water, min(height[left], height[right])*(right - left));
			if(height[left] < height[right])	left++;
			else	right--;
		}
		return water;
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
