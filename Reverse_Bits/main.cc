#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	uint32_t reverseBits(uint32_t n) {
		uint32_t result = 0;
		for(int i = 0; i < 16; i++){
			bool front = n & (0x1 << (31 - i));
			bool back = n & (0x1 << i);
			result = result | (back << (31 - i));
			result = result | (front << i);
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.reverseBits(43261596u)<<endl;

	return 0;

}
