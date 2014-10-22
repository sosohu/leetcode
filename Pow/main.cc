#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	
	double pow(double x, int n) {
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

};

int main(int argc, char** argv)
{
	Solution sl;
    double ret = sl.pow(1.2312, -3);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}