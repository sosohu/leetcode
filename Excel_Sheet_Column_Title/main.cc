#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	string convertToTitle(int n) {
 		return n <= 0? "" : convertToTitle((n-1)/26) + string(1,((n-1) % 26) + 'A');   	    
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.convertToTitle(27)<<endl;

	return 0;

}
