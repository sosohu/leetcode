#include <iostream>


using namespace std;


class Solution {

public:

    bool isPowerOfTwo(int n) {
        if(n == INT_MIN)    return false;
        int count = 0;
        while(n){
            n = n & (n - 1);
            count++;
        }
        return count == 1;
    }


};

int main(int argc, char** argv)
{
	Solution sl;
	return 0;
}
