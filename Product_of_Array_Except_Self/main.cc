#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for(int i = 0; i < n-1; i++){
            res[i+1] = res[i] * nums[i];
        }
        for(int i = n-2; i >= 0; i--){
            res[i] = res[i] * nums[i+1];
            nums[i] = nums[i]*nums[i+1];
        }
        return res;
    }
};

int main(int argc, char** argv)
{
	Solution sl;

	return 0;
}
