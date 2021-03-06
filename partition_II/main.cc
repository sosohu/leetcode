#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;



void print(vector<vector<string> > data){
	int len = data.size();
	int size;
	cout<<endl<<endl<<"PRINT MSG"<<endl;
	for(int i = 0; i < len; i++){
		size = data[i].size();
		for(int j = 0; j < size; j++){
			cout<<data[i][j]<<" ";
		}
		cout<<endl;
	}
}

class Solution {

public:

	bool is_palindrome(string& s){
		int len = s.length();
		for(int i = 0; i < len / 2; i++){
			if(s[i] != s[len - 1 - i])
				return false;
		}
		return true;
	}

	int minCut_1st(string s) {
		int len = s.length();
		bool P[len][len];
		
		for(int i = 0; i < len; i++){
			P[i][i] = true;
			if(i < len -1 && s[i] == s[i+1]) 
				P[i][i+1] = true;
			else
				P[i][i+1]  = false;
		}
		
		int j;
		for(int step = 3; step <= len; step++){
			for(int i = 0; i <= len - step; i++){
				j = i + step - 1;
				if(s[i] == s[j] && P[i+1][j-1])
					P[i][j] = true;
				else
					P[i][j] = false;
			}
		}

		if(P[0][len-1]) return 0;

		int min[len];
		min[0] = 0;

		for(int step = 1; step < len; step++){
			if(P[0][step]) { min[step] = 0; continue;}
			int tmp = step;
			for(int i = step ; i > 0; i--){
				if(P[i][step] && tmp > min[i - 1] + 1 ){
					tmp = min[i-1] + 1;
				}
			}
			min[step] = tmp;
		}
		
		return min[len-1];
	}

	int minCut(string s) {
		int n = s.size();
		vector<vector<bool> > palin(n, vector<bool>(n, false));
		for(int i = 0; i < n; i++){
			for(int j = 0; i + j < n && i - j >= 0; j++){
				if(s[i-j] == s[i+j]) palin[i-j][i+j] = true;
				else break;
			}
		}
		for(int i = 0; i < n-1; i++){
			for(int j = 0; i + j < n - 1 && i - j >= 0; j++){
				if(s[i-j] == s[i+j+1]) palin[i-j][i+j+1] = true;
				else break;
			}
		}
		vector<int> dp(n+1, 0);
		for(int i = 0; i < n; i++){
			int minCur = INT_MAX;
			for(int j = 0; j <= i; j++){
				if(palin[j][i]){
					minCur = min(minCur, dp[j] + 1);
				}
			}
			dp[i+1] = minCur;
		}
		return dp[n] - 1;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	//string s("adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece");		
	string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	int ret;
	ret = sl.minCut(s);
	
	cout<<ret<<endl;

	//print(ret);
	
	return 0;

}
