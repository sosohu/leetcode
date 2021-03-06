#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {

public:

	int numDistinct_1st(string S, string T) {
		int nt = T.length();
		int ns = S.length();
		if(nt == 0 || ns == 0)
			return 0;
		
		unordered_map<char, vector<int> > pos;
		for(int i = 0; i < nt; i++){
			if(pos.count(T[i]) == 0){
				vector<int> vec;
				vec.push_back(i);
				pos[T[i]] = vec;
			}else{
				pos[T[i]].push_back(i);
			}
		}

		vector<int> q;
		for(int i = 0; i < nt; i++)
			q.push_back(0);

		char c;
		vector<int> spos;
		int tmp;
		for(int i = ns -1; i >= 0; i--){
			c = S[i];
			if(pos.count(c) == 1){
				spos = pos[c];
				for(int j = 0; j < spos.size(); j++){
					tmp = spos[j];
					if(tmp == nt - 1)
						q[tmp]++;
					else
						q[tmp] = q[tmp+1] + q[tmp];
				}
			}
		}
		return q[0];
    }

	int numDistinct(string S, string T) {
		int n = S.size();
		int m = T.size();
		vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
		for(int j = 0; j < m; j++)
			for(int i = j; i < n; i++){
				if(S[i] == T[j]){
					dp[i+1][j+1] = dp[i][j+1] + (j == 0? 1 : dp[i][j]);
				}else{
					dp[i+1][j+1] = dp[i][j+1];
				}
			}
		return dp[n][m];
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	//string s("aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe"), t("bddabdcae");		
	string s("rabbbit"), t("rabbit");
    int ret = sl.numDistinct(s,t);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
