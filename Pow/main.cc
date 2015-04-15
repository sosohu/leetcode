#include <iostream>
#include <string>
#include <climits>

using namespace std;


class Solution {

public:

	
	double pow_1st(double x, int n) {
		if(n == 0)	return 1.0;
		if(n > 0)	return recursion(x, n);
		else		return 1.0 / (x*recursion(x, -(n+1))); // -n maybe overflow
	}

	double recursion(double x, int n) {
	    if(n == 0)	return 1.0;
		if(n == 1)	return x;
		int half = n / 2;
		double data = recursion(x, half);
		data = data * data;
		if(half * 2 != n)
			data = data * x;
		return data;
    }

	// return x^(count)
	double pow2n(double x, int& n){
		int count = 1;
		while(count < n>>1){
			x = x * x;
			count = count<<1;
		}
		n = n - count;
		return x;
	}

	double pow(double x, int n) {
		if(n == 0)	return 1;
		if(n < 0)	return n == INT_MIN? 1.0/(x * pow(x, INT_MAX)) : 1.0/pow(x, -n);
		double result = 1.0;
		while(n) result = result * pow2n(x, n);	
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
    double ret = sl.pow(1.00000, -2147483648);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
