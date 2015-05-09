/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-05-09 18:29
 * Filename :        main.cc
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#include <iostream>

using namespace std;


class Solution {

public:

	int hammingWeight(uint32_t n) {
		int count = 0;
		while(n){
			n = (n & (n - 1));
			count++;
		}
		return count;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.hammingWeight(11u)<<endl;

	return 0;

}
