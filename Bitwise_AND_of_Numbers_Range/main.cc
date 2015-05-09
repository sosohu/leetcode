#include <iostream>
#include <climits>

using namespace std;


class Solution {

public:

	int rangeBitwiseAnd(int m, int n) {
		if(m == 0 && n == INT_MAX)	return 0;
		int gap = n - m + 1;
		if(gap <= 1)	return n;
		int pos = 0;
		while(pos < 32 && ((1 << pos) - (m & (~(0xffffffff - ((1 << pos) - 1)))) < gap))
			pos++;
		return n & (0xffffffff - ((1 << pos) - 1));
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	
	cout<<sl.rangeBitwiseAnd(2,3)<<endl;

	return 0;

}
