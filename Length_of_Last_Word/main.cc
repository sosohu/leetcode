#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int lengthOfLastWord(const char *s) {
		int length;
		int pos = 0;
		while(s[pos] != '\0' && s[pos] == ' '){
			pos++;
		}
		if(s[pos] == '\0')	return 0;
		while(1){
			length = 0;
			while(s[pos] != '\0' && s[pos] != ' '){
				pos++;
				length++;
			}
			while(s[pos] != '\0' && s[pos] == ' '){
				pos++;
			}
			if(s[pos] == '\0') return length;
		}
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	const char* s = "  hello my world ada ";		
    int ret = sl.lengthOfLastWord(s);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
