#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

    void reverseWords(string &s) {
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("  hello my world ada ");		
    sl.reverseWords(s);
	
	cout<<"Result  :("<<s<<")"<<endl;

	return 0;

}
