#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

    void reverseWords(string &s) {
        int len = s.length();
		if(len == 0)
			return;

		int mid = -1;
		for(int i = len / 2, j = len / 2; i >= 0 || j <= len -1; i--, j++ ){
			if(i >= 0 && s[i] == ' '){
					mid = i;
					break;
			}
			if(j <= len - 1 && s[j] == ' '){
					mid = j;
					break;
			}
		}

		if(mid == -1)
			return;

		string down(s, mid + 1, len - mid - 1);
		string up(s, 0,  mid);
		reverseWords(down);
		reverseWords(up);

		s.replace(0,len - mid - 1, down, 0, len - mid -1);
		s.replace(len - mid, mid, up, 0, mid);
		
		s[len - mid -1] = ' ';
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
