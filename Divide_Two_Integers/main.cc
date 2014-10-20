#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int divide(int dividend, int divisor) {
		bool minus = false;

		if(dividend < 0 && divisor < 0){
			dividend = -dividend;
			divisor = -divisor;
		}

		if(dividend < 0 && divisor > 0){
			dividend = -dividend;
			minus = true;
		}
	
		if(dividend > 0 && divisor < 0){
			divisor = -divisor;
			minus = true;
		}

		if(dividend < divisor)	return 0;
		int high = 1;
		int low = 1;
		int sum = divisor;
		int dividend_use = 0;
		while(sum <= dividend){
			dividend_use = sum;
			sum =  sum + sum;
			dividend_use = sum - dividend_use;
			low = high;
			high = high + high;
			low = high - low;
		}
		int left = divide( dividend - dividend_use , divisor);
		if(minus)
			return -low - left;
		else
			return low + left;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
    int ret = sl.divide(1, 1);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
