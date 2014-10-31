#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	string longestPalindrome(string const& s) {
		int size = s.length();
		string str;
		if(size == 0)	return str;
		int max = 1, next = 1;
		int max_first = 0, next_first = 0;
		bool same = true;
		for(int i = 1; i < size; i++){
			if(s[i] != s[i-1])	same = false;
			if(same){
				next++;
			}else{
				if(next_first > 0 && s[i] == s[next_first - 1]){
					next = next + 2;
					next_first--;
				}
				else{
					same = true;
					next_first = i;
					next = 1;
				}
			}
			if(next > max){
				max = next;
				max_first = next_first;
			}
		}
		return s.substr(max_first, max);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("bananas");		
    string ret = sl.longestPalindrome(s);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
