/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-05-25 14:01
 * Filename :        main.cc
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {

public:

	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> table;
		for(int i = 0; i < nums.size(); i++){
			if(table.count(nums[i]))	return true;
			table.insert(nums[i]);
		}
		return false;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> nums{1,2,3,4,5,6,7};

	cout<<sl.containsDuplicate(nums)<<endl;

	return 0;

}
