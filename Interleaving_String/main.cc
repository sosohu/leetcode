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
		char f1, f2, f3;
		f1 = s2[len1 - 1];
		f2 = s2[len2 - 1];
		f3 = s3[len3 - 1];
		int i = 0;
		for(; i < len1 && i < len2 && i < len3; i++){
			c1 = s1[len1 - 1 - i];	
			c2 = s2[len2 - 1 - i];
			c3 = s3[len3 - 1 - i];
			if(c1 != c2 || c1 != c3 )	break;
		}
		//if(i == 0 && c1 != c3 && c2 != c3)	return false;
		if(f1 != c3 && f2 != c3 && c1 != c3 && c2 != c3)	return false;
		#ifdef DEBUG
		cout<<"s1: "<<s1.substr(0,len1)<<" s2: "<<s2.substr(0,len2)<<" s3: "<<s3.substr(0,len3)<<endl;	
		cout<<"i "<<i<<endl;
		#endif

		if(i == len1) return recursion(s1, s2, s3, 0, len2, len3-len1)
							 || recursion(s1, s2, s3, len1, len2-len1, len3-len1);
		if(i == len2) return recursion(s1, s2, s3, len1, 0, len3-len2)
							 || recursion(s1, s2, s3, len1-len2, len2, len3-len2);

		c1 = s1[len1 - 1 - i];	
		c2 = s2[len2 - 1 - i];
		c3 = s3[len3 - 1 - i];
		#ifdef DEBUG
		cout<<"c1: "<<c1<<" c2: "<<c2<<" c3: "<<c3<<endl;	
		#endif
		if(i != 0){
			return recursion(s1, s2, s3, len1- i, len2, len3-i)
				   ||  recursion(s1, s2, s3, len1, len2-i, len3-i);
		}
		else{
			if(c1 == c3)
				return recursion(s1, s2, s3, len1- 1, len2, len3-1);
			if(c2 == c3)
				return recursion(s1, s2, s3, len1, len2-1, len3-1);
		}
		return false;
}

bool iteration(string s1, string s2, string s3){
		int len1 = s1.length();
		int len2 = s2.length();
		int len3 = s3.length();

		vector<vector<bool> > data(len1+1, vector<bool>(len2+1, true));

		for(int i = 1; i < len1+1; i++)
			data[i][0] = data[i-1][0] && (s1[i-1] == s3[i-1]);
		for(int i = 1; i < len2+1; i++)
			data[0][i] = data[0][i-1] && (s2[i-1] == s3[i-1]);

		for(int i = 1; i < len1+1; i++){
			for(int j = 1; j < len2+1; j++){
				data[i][j] = (data[i-1][j] && s1[i-1] == s3[i+j-1])
							|| (data[i][j-1] && s2[j-1] == s3[i+j-1]);
			}
		}
		return data[len1][len2];
	}

bool isInterleave_1st(string s1, string s2, string s3) {
		//return recursion(s1, s2, s3, s1.length(), s2.length(), s3.length());
		return iteration(s1, s2, s3);
    }

bool isInterleave(string s1, string s2, string s3) {
	int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
	if(n1 + n2 != n3) return false;
	vector<vector<int> > dp(n1+1, vector<int>(n2+1, false));
	dp[0][0] = true;
	for(int i = 0; i < n1; i++)
		if(s1[i] == s3[i])	dp[i+1][0] = true;
		else	break;
	for(int i = 0; i < n2; i++)
		if(s2[i] == s3[i])	dp[0][i+1] = true;
		else	break;
	for(int i = 0; i < n1; i++)
		for(int j = 0; j < n2; j++){
			dp[i+1][j+1] = (s1[i] == s3[i+j+1] && dp[i][j+1])
							|| (s2[j] == s3[i+j+1] && dp[i+1][j]);
		}
	return dp[n1][n2];
}

};

int main(int argc, char** argv)
{
	Solution sl;
	//string s1("aabcc"), s2("dbbca"), s3("aadbbcbcac");
	string s1("baababbabbababbaaababbbbbbbbbbbaabaabaaaabaaabbaaabaaaababaabaaabaabbbbaabbaabaabbbbabbbababbaaaabab"), s2("aababaaabbbababababaabbbababaababbababbbbabbbbbababbbabaaaaabaaabbabbaaabbababbaaaababaababbbbabbbbb"), s3("babbabbabbababbaaababbbbaababbaabbbbabbbbbaaabbabaababaabaaabaabbbaaaabbabbaaaaabbabbaabaaaabbbbababbbababbabaabababbababaaaaaabbababaaabbaabbbbaaaaabbbaaabbbabbbbaaabaababbaabababbbbababbaaabbbabbbab");

	bool ret = sl.isInterleave(s1, s2, s3);

	cout<<"Result: ("<<ret<<")"<<endl;

	return 0;

}
