#include <iostream>

using namespace std;


class Solution {

public:
	int addDigits(int num) {
		int sum;
		L1:
		sum = 0;
		L2:
		sum = sum + (num % 10);
		num = num / 10;
		if(num != 0) goto L2;
		num = sum;
 		if(num < 10)	return num;
		goto L1;
    }
};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.addDigits(1110)<<endl;

	return 0;

}
