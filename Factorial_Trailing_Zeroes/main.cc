#include <iostream>

using namespace std;


class Solution {

public:

	int trailingZeroes(int n) {
		return abs(n) < 5?  0 : abs(n/5) + trailingZeroes(n/5);
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.trailingZeroes(-6)<<endl;

	return 0;

}
