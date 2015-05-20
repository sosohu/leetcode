#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int titleToNumber(string s) {
		return s.size()? titleToNumber(s.substr(0, s.size() - 1))*26 + s[s.size()-1] - 'A' + 1: 0;		
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.titleToNumber("AA")<<endl;

	return 0;

}
