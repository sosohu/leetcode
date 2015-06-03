#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

	string shortestPalindrome(string s) {
		int n = s.size();
		if(n == 0)	return s;
		string s_sharp(1, '#');
		for(int i = 0; i < n; i++){
			s_sharp.push_back(s[i]);
			s_sharp.push_back('#');
		}
		vector<int> p(2*n+1, 0); // 刨除本身左右长度
		p[1] = 1;
		int id = 1, mx = 2; // mx 为右边界,包含
		int maxLen = 1;
		for(int i = 2; i < 2*n+1; i++){
			int j = 2*id - i;
			if(p[j] < mx - i){
				p[i] = p[j];
			}else{
				int pos = mx;
				while(pos < 2*n+1 && 2*i - pos >= 0 && s_sharp[pos] == s_sharp[2*i - pos])
					pos++;
				p[i] = pos - i - 1;
				mx = pos - 1;
				id = i;
			}
			if(p[i] == i){
				maxLen = max(maxLen, i);
			}		
		}
		string add = s.substr(maxLen, n - maxLen);
		reverse(add.begin(), add.end());
		return add + s;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.shortestPalindrome("ababbbabbaba")<<endl;

	return 0;

}
