#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	string longestPalindrome(string const& s) {
		int size = s.length();
		string str;
		if(size == 0)	return str;
		int max = 1, start = 0;
		int pre, next, cur;
		for(int i = 1; i < size; i++){
			pre = i - 1 ;
			next = i;
			cur = 0;
			while(pre > -1 && next < size & s[pre] == s[next]){
				pre--;
				next++;
				cur = cur + 2;
			}
			if(cur > max){
				max = cur;
				start = pre + 1;
			}
			pre = i - 1 ;
			next = i + 1;
			cur = 1;
			while(pre > -1 && next < size & s[pre] == s[next]){
				pre--;
				next++;
				cur = cur + 2;
			}
			if(cur > max){
				max = cur;
				start = pre + 1;
			}
		}
		return s.substr(start, max);
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
