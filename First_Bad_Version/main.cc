#include <iostream>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		long long low = 1, high = n, mid;
		while(low <= high){
			mid = (low + high) / 2;
			if(!isBadVersion(mid)){
				high = mid - 1;
			}else{
				low = mid + 1;
			}
		}
		return high + 1;	
    }
};

int main(int argc, char** argv)
{
	Solution sl;

	return 0;

}
