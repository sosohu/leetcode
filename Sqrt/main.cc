#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int sqrt_1st(int x) {
		if(x < 2) return x;
		int pos = x/2;
		while(!(pos <= x/pos && (pos+1) >= x/(pos+1))){
			pos = pos/2 + x/(2*pos);
		}
		if((pos+1) == x/(pos+1))	return pos+1;
		return pos;
    }

	int sqrt(int x) {
		if(x < 2)	return x;
		int low = 1, high = x/2;
		while(low <= high){
			int mid = (low + high) / 2;
			if(mid == x/mid)	return mid;
			if(mid > x/mid)	high = mid - 1;
			else	low = mid + 1;
		}
		return high;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
    int ret = sl.sqrt(2147395600);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
