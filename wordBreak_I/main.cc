#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;


class Solution {

public:

	bool wordBreak_1st(string s, unordered_set<string> &dict) {
		int len = s.length();
		if(len == 0)
			return false;
		bool data[len][len];
		string tmp;
		for(int i = 0; i < len; i++){
			tmp = s.substr(i,1);
			if(dict.count(tmp) == 1)
				data[i][i] = true;
			else
				data[i][i] = false;
		}
		for(int step = 2; step <= len; step++){
			for(int i = 0; i <= len - step; i++){
				tmp = s.substr(i, step);
				data[i][i+step-1] = false;
				for(int j = i; j < i + step - 1; j++){
					if(data[i][j] && data[j+1][i+step-1]){
						data[i][i+step-1] = true;
						break;
					}
				}
				if(dict.count(tmp) == 1){
					data[i][i+step-1] = true;
				}
			}
		}
		//cout<<data[0][len-1]<<endl;
		return data[0][len-1];
	}

	bool wordBreak(string s, unordered_set<string> &dict) {
		int n = s.size();
		vector<bool> dp(n+1, false);
		dp[0] = true;
		for(int i = 0; i < n; i++){
			for(int j = i; j >= 0; j--){
				if(dict.count(s.substr(j, i - j + 1)) != 0){
					dp[i+1] =  dp[j];
					if(dp[i+1])	break;
				}
			}
		}
		return dp[n];
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
	unordered_set<string> d({"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"});
	bool ret = sl.wordBreak(s,d);
	if(ret)
		cout<<"ture"<<endl;
	else
		cout<<"false"<<endl;
	return 0;

}
