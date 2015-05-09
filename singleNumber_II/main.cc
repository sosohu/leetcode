#include <iostream>
#include <vector>

using namespace std;

#define DATASIZE 10

class Solution {

public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		vector<int> b(32, 0);
		for(int i = 0; i < 32; i++){
			for(int j = 0; j < nums.size(); j++){
				b[i] += (((nums[j] >> i) & 0x1) != 0);
			}
			b[i] %= 3;
			result += (b[i] << i);
		}
		return result;
	}

	int singleNumber(int A[], int n) {
		if(n == 1) return A[0];
		int sum = 0;
		unsigned int mask = 1;
		int tmp = 0;
		for(int i = 0; i < 32; i++){
			tmp = 0;
			for(int j = 0; j < n; j++){
				tmp += ((A[j] >> i) & mask);
			}
			tmp = tmp % 3;
			if(tmp)
				sum |= (mask << i);
		}

		return (int)sum;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int d[DATASIZE*3 + 1] = {0};
	for(int i = 0; i < DATASIZE; i++){
		d[i] = -i*2 + 1;
		d[DATASIZE + i] = -i*2 + 1;
		d[2*DATASIZE + i ] = -i*2 + 1;
	}
	d[3*DATASIZE] = 3*DATASIZE - 100;
	for(int i = 0; i < DATASIZE ; i++)
		cout<<d[i]<<" "<<d[DATASIZE + i]<<" "<<d[2*DATASIZE + i]<<endl;
	cout<<d[3*DATASIZE]<<endl;
	vector<int> data(&d[0], &d[0] + 3*DATASIZE + 1);
    int ret = sl.singleNumber(data);
	
	cout<<"Result  : "<<ret<<endl;

	return 0;

}
