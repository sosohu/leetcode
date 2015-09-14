#include <iostream>

using namespace std;


class Solution {

public:

	bool isUgly(int num) {
		if(num < 1)	return false;
		while(num > 1 && num % 2 == 0){
			num = num / 2;
		}
		while(num > 1 && num % 3 == 0){
			num = num / 3;
		}
		while(num > 1 && num % 5 == 0){
			num = num / 5;
		}
		return num == 1;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.isUgly(24)<<endl;

	return 0;

}
