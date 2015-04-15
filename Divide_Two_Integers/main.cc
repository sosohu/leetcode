#include <iostream>
#include <string>
#include <climits>

using namespace std;


class Solution {

public:

	int divide_1st(int dividend, int divisor) {
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

	int div2n(int &dividend, int divisor){
		if(dividend > divisor){
			dividend = 0;
			return 0;
		}
		int i = 1;
		while(divisor > dividend - divisor ){
			divisor +=divisor;
			i = i + i;
		}
		dividend -= divisor;
		return i;
	}

	int divide(int dividend, int divisor) {
		bool isMinus = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
		dividend = dividend < 0? dividend : -dividend;
		divisor = divisor < 0? divisor : -divisor;
		int result = 0;
		while(dividend){
			result -= div2n(dividend, divisor);
		}
		return isMinus? result : (result == INT_MIN? INT_MAX : -result);
	}

};

int main(int argc, char** argv)
{
	Solution sl;
    int ret = sl.divide(-2147483648, -1);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
