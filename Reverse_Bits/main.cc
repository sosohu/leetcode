#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	uint32_t reverseBits_1st(uint32_t n) {
		uint32_t result = 0;
		for(int i = 0; i < 16; i++){
			bool front = n & (0x1 << (31 - i));
			bool back = n & (0x1 << i);
			result = result | (back << (31 - i));
			result = result | (front << i);
		}
		return result;
	}

	uint32_t reverseBits(uint32_t n) {
		n=((n & 0xffff0000) >> 16)| ((n & 0x0000ffff) << 16);
        n=((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n=((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n=((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n=((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.reverseBits(43261596u)<<endl;

	return 0;

}
