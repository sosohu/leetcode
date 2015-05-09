/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-05-09 16:32
 * Filename :        main.cc
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

#define DATASIZE 10

class Solution {

public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for(int i = 0; i < nums.size(); i++)
			result ^= nums[i];
		return result;
	}

	int singleNumber_Tradition(int A[], int n) {
		if(n == 1) return A[0];
		int sum = 0;
		unsigned int mask = 1;
		int tmp = 0;
		for(int i = 0; i < 32; i++){
			tmp = 0;
			for(int j = 0; j < n; j++){
				tmp += ((A[j] >> i) & mask);
			}
			tmp = tmp % 2;
			if(tmp)
				sum |= (mask << i);
		}

		return (int)sum;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int d[DATASIZE*2 + 1] = {0};
	for(int i = 0; i < DATASIZE; i++){
		d[i] = -i*2;
		d[DATASIZE + i] = -i*2;
	}
	d[2*DATASIZE] = 2*DATASIZE - 100;
	for(int i = 0; i < DATASIZE ; i++)
		cout<<d[i]<<" "<<d[DATASIZE + i]<<endl;
	cout<<d[2*DATASIZE]<<endl;
	vector<int> data(&d[0], &d[0] + 2*DATASIZE + 1);
    int ret = sl.singleNumber(data);
	
	cout<<"Result  : "<<ret<<endl;

	return 0;

}
