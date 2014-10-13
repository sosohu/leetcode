#include <iostream>
#include <string>

using namespace std;

#define DATASIZE 10

class Solution {

public:
	int singleNumber(int A[], int n) {
		if(n == 1) return A[0];
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum = (~(sum & A[i])) & (sum | A[i]);
		}
		return sum;
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
    int ret = sl.singleNumber(d, 2*DATASIZE + 1);
	
	cout<<"Result  : "<<ret<<endl;

	return 0;

}
