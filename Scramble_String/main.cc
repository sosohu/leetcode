#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

	bool iteration(string s1, string s2){
		int len = s1.length();
		// 1st mark the start of s1, 2nd mark the start of s2, 3rd mark the length
		vector<vector<vector<bool> > > data(len, vector<vector<bool> >(len, vector<bool>(len, false)));

		for(int i = 0; i < len; i++){
			for(int j = 0; j < len; j++){
				data[i][j][0] = s1[i] == s2[j];
			}
		}

		for(int step = 1; step < len; step++){
			for(int i = 0; i < len - step; i++){
				for(int j = 0; j < len - step; j++){
					bool tmp = false;
					for(int d = 0; d < step; d++){
						tmp = tmp 
							|| (data[i][j][d] && data[i+d+1][j+d+1][step-d-1]) 
					     	|| (data[i][j+step-d][d] && data[i+d+1][j][step-d-1]); 
					}
					data[i][j][step] = tmp;
				}
			}
		}
		return data[0][0][len-1];
	}
	
	// very slow
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

	bool isScramble_1st(string s1, string s2) {
		if(s1.length() <= 0)	return false;
		if(s1.compare(s2) == 0)
			return true;
		//return recursion(s1, s2);
		return iteration(s1, s2);
	}

	bool isScramble(string s1, string s2) {
		int n = s1.size();
		if(n == 0 || s1.size() != s2.size() ) return false;
		vector<vector<vector<bool> > > dp(n, vector<vector<bool> >(n, vector<bool>(n+1, false)));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				dp[i][j][1] = s1[i] == s2[j];
		for(int l = 2; l < n+1; l++){
			for(int i = 0; i <= n - l; i++)
				for(int j = 0; j <= n - l; j++){
					for(int k = 1; k < l; k++){
						dp[i][j][l] = dp[i][j][l] || (dp[i][j][k] && dp[i+k][j+k][l-k])
										|| (dp[i][j+l-k][k] && dp[i+k][j][l-k]);
					}
				}
		}
		return dp[0][0][n];
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	string s1("xstjzkfpkggnhjzkpfjoguxvkbuoip"), s2("xbouipkvxugojfpkzjhnggkpfkzjts");		

	bool ret = sl.isScramble(s1, s2);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
