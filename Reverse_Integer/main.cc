#include <iostream>
#include <climits>
#include <cmath>

using namespace std;


class Solution {

public:

	int reverse_1st(int x) {
		int rever = 0;
		while(x != 0){
			rever = rever * 10 + x % 10;
			x = x / 10;
		}
		return rever;
    }

	int reverse (int x) {
		if(x > 0)	return -reverse(-x);
		int rever = 0;
		while(x != 0){
			if(rever < (INT_MIN - x%10) / 10)
				return 0;
			rever = rever * 10 + x % 10;
			x = x / 10;
		}
		return rever;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
    int ret = sl.reverse(INT_MIN);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
