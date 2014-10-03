#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	bool recursion(string s1, string s2) {
		int len = s1.length();
		if(len <= 0) return false;
		if(len == 1 && s1[0] == s2[0]) return true;
		
		if(s1[0] == s2[len-1] && recursion(s1.substr(1, len-1), s2.substr(0, len-1)))	return true;	
		if(s1[0] == s2[0] && recursion(s1.substr(1, len-1), s2.substr(1, len-1)))	return true;	

		bool ret = false;
		for(int i = 2; i < len-2; i++){
			ret = ret || (recursion(s1.substr(0,i), s2.substr(0,i)) 
					   && recursion(s1.substr(i, len-i), s2.substr(i, len-i)))
					  || (recursion(s1.substr(0,i), s2.substr(len-i, i))
					   && recursion(s1.substr(i, len-i), s2.substr(0,len-i)));	
		}

		if(s1[len-1] == s2[0] && recursion(s1.substr(0, len-1), s2.substr(1, len-1)))	return true;	
		if(s1[len-1] == s2[len-1] && recursion(s1.substr(0, len-1), s2.substr(0, len-1)))	return true;	
		return ret;
    }

	bool isScramble(string s1, string s2) {
		if(s1.length() <= 1)	return false;
		if(s1.compare(s2) == 0)
			return false;
		return recursion(s1, s2);
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	string s1("gr"), s2("gr");		

	bool ret = sl.isScramble(s1, s2);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
