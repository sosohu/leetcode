#include <iostream>
#include <string>

using namespace std;


class Solution {

public:
	inline bool isAlpha(char c){
		if(c <= 'Z' && c >= 'A')
			return true;
		if(c <= 'z' && c >= 'a')
			return true;
		if(c <= '9' && c >= '0')
			return true;
		return false;
	}

	inline bool isequal(char lfs, char rhs){
		if(lfs == rhs || lfs - 32 == rhs || lfs == rhs - 32)	return true;
		return false;
	}

	bool isPalindrome(string s) {
		string tmp;
		int size = s.size();
		if(size <= 1) return true;
		for(int i = 0, j = size - 1 ; i < size; i++, j--){
			while(!isAlpha(s[i])){
				i++;
				if(i > size - 1) return true;
			}
			while(!isAlpha(s[j])){
				j--;
				if(j < 0)  return true;
			}
			if(i >= j) return true;
			if(!isequal(s[i], s[j])) return false;
		}
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("2a2");		
    bool ret = sl.isPalindrome(s);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
