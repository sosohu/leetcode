#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

	int longestValidParentheses_1st(string s) {
		int len = s.length();
		stack<int>	sk;
		int pos = 0;
		while(pos < len && s[pos] == ')'){
			pos++;
		}
		int last = 0;
		int cur, last_pos;
		int start = pos - 1;
		for(; pos < len; pos++){
			if(s[pos] == ')'){
				if(!sk.empty()){
					sk.pop();
					if(sk.empty()){
						cur = pos - start;
					}else{
						last_pos = sk.top();
						cur = pos - last_pos;
					}
					last = last > cur? last : cur;
				}else{
					start = pos;
				}
			}else{
				sk.push(pos);
			}
		}
		return last;
    }

	int longestValidParentheses(string s) {
		int size = s.size();
		vector<int> dp(size + 1, 0);
		int max = 0;
		for(int i = size - 2; i >= 0; i--){
			if(s[i] == '('){
				if(s[i+1] == ')'){
					dp[i] = 2 + dp[i+2];
				}else{
					if(i + dp[i+1] < size - 1){
						if(s[i + dp[i+1] + 1] == ')')
					 		dp[i] = 2 + dp[i+1] + dp[i + dp[i+1] + 2];
					}
				}
			}
			if(max < dp[i])
				max = dp[i];
		}
		return max;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	string s(")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())");		
    int ret = sl.longestValidParentheses(s);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
