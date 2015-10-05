#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
 		int res = 1, n = nums.size(), count = 0;
 	    while(res < n){
 	        count = 0;
		    for(int i = 0; i < n; i++){
			    if(nums[i] == res){
			        count++;
			    }
		    }
		    if(count > 1)   return res;
		    res++;
 	    }
    }
};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{1, 2, 3, 3, 4};
	cout<<sl.findDuplicate(nums)<<endl;

	return 0;
}
