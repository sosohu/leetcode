/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-05-09 17:14
 * Filename :        main.cc
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

    int majorityElement_1st(vector<int>& nums) {
		if(nums.size() == 0)	return -1;
		int p1 = nums[0], p2, c1 = 1, c2 = 0;
		for(int i = 1; i < nums.size(); i++){
			if(c1 && nums[i] == p1)	c1++;
			else	if(c2 && nums[i] == p2)	c2++;
			else	if(!c1){
				p1 = nums[i];
				c1++;
			}
			else	if(!c2){
				p2 = nums[i];
				c2++;
			}else{
				c1--;
				c2--;
			}
		}
		return c1 > c2? p1 : p2;
    }

    int majorityElement(vector<int>& nums) {
		int result = 0, n = nums.size();
		for(int i = 0; i < 32; i++){
			int bit = 0;
			for(int j = 0; j < n; j++)
				bit += ((nums[j] & (0x1 << i))? 1 : 0);
			result += ((bit > n/2? 1 : 0) << i);
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{1,2,3,1,2,3,1,1,1};
	cout<<sl.majorityElement(nums)<<endl;

	return 0;

}
