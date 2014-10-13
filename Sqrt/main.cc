#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int sqrt(int x) {
		if(x < 2) return x;
		int pos = x/2;
		while(!(pos <= x/pos && (pos+1) >= x/(pos+1))){
			pos = pos/2 + x/(2*pos);
		}
		if((pos+1) == x/(pos+1))	return pos+1;
		return pos;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
    int ret = sl.sqrt(2147395600);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
