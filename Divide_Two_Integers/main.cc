#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int divide(int dividend, int divisor) {
		bool minus = false;

		if(divisor == 1)    return dividend;
	    if(divisor == -1)    return -dividend;

		if(divisor == -1<<31){
			if(dividend == -1<<31)	return 1;
			return 0;
		}

		if(dividend > 0 && divisor > 0){
			dividend = -dividend;
			divisor = -divisor;
		}

		if(dividend > 0 && divisor < 0){
			dividend = -dividend;
			minus = true;
		}
	
		if(dividend < 0 && divisor > 0){
			divisor = -divisor;
			minus = true;
		}

		if(dividend > divisor)	return 0;
		int high = 1;
		int low = 1;
		int sum = divisor;
		int dividend_use = 0;
		while(sum >= dividend && sum >= -1<<30){
			dividend_use = sum;
			sum =  sum + sum;
			dividend_use = sum - dividend_use;
			low = high;
			high = high + high;
			low = high - low;
		}
		if(sum >= dividend){
			dividend_use = sum - dividend_use;
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
    int ret = sl.divide(-2147483648, 2);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
