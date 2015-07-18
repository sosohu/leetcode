#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
		deque<pair<int, int> > window;
		vector<int> res;
		for(int i = 0; i < n; i++){
			int sz = window.size();
			for(int j = sz - 1; j >= 0; j--){
				if(nums[i] >= window[j].first){
					window.pop_back();
				}else{
					break;
				}
			}
			window.push_back(make_pair(nums[i], i));
			if(i >= k-1){
				if(i > k-1){
					if(window[0].second + k <= i){
						window.pop_front();
					}
				}
				res.push_back(window[0].first);
			}
		}
		return res;
    }
};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{1,3,-1,-3,5,3,6,7};
	vector<int> res = sl.maxSlidingWindow(nums, 3);
	for(auto ele : res)
		cout<<ele<<endl;
	return 0;
}
