#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <cassert>

using namespace std;

class Solution {

public:

bool recursion(string& s1, string& s2, string& s3, int len1, int len2, int len3){
		
		if(len1 + len2 != len3)
		    return false;
		
		int zero = 1;
		zero = len1 * len2 * len3;

		if(!zero){
			if(!len1 && !len2 && !len3)
				return true;
			if(!len1 && len2 && len3){
				string str2 = s2.substr(0, len2);
				string str3 = s3.substr(0, len3);
				if(str2.compare(str3) == 0)	return true;
				else	return false;
			}
			if(len1 && !len2 && len3){
				string str1 = s1.substr(0, len1);
				string str3 = s3.substr(0, len3);
				if(str1.compare(str3) == 0)	return true;
				else	return false;
			}
			return false;
		}

		char c1, c2, c3;
		//int i = 0;
		//for()

		c1 = s1[len1 - 1];	
		c2 = s2[len2 - 1];
		c3 = s3[len3 - 1];
		#ifdef DEBUG
		cout<<"s1: "<<s1.substr(0,len1)<<" s2: "<<s2.substr(0,len2)<<" s3: "<<s3.substr(0,len3)<<endl;	
		#endif

		if(c1 == c2){
			if(c1 == c3){
				return recursion(s1, s2, s3, len1-1, len2, len3-1)
						|| recursion(s1, s2, s3, len1, len2-1, len3-1);
			}
		}else{
			if(c1 == c3){
				return recursion(s1, s2, s3, len1-1, len2, len3-1);
			}
			if(c2 == c3){
				return recursion(s1, s2, s3, len1, len2-1, len3-1);
			}
		}
		return false;
}

bool isInterleave(string s1, string s2, string s3) {
		return recursion(s1, s2, s3, s1.length(), s2.length(), s3.length());
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	string s1("baababbabbababbaaababbbbbbbbbbbaabaabaaaabaaabbaaabaaaababaabaaabaabbbbaabbaabaabbbbabbbababbaaaabab"), s2("aababaaabbbababababaabbbababaababbababbbbabbbbbababbbabaaaaabaaabbabbaaabbababbaaaababaababbbbabbbbb"), s3("babbabbabbababbaaababbbbaababbaabbbbabbbbbaaabbabaababaabaaabaabbbaaaabbabbaaaaabbabbaabaaaabbbbababbbababbabaabababbababaaaaaabbababaaabbaabbbbaaaaabbbaaabbbabbbbaaabaababbaabababbbbababbaaabbbabbbab");

	bool ret = sl.isInterleave(s1, s2, s3);

	cout<<"Result: ("<<ret<<")"<<endl;

	return 0;

}
