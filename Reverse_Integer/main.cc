#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int reverse (int x) {
		int rever = 0;
		while(x != 0){
			rever = rever * 10 + x % 10;
			x = x / 10;
		}
		return rever;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
    int ret = sl.reverse(-1231423);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
