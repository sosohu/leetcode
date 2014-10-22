#include <iostream>
#include <string>
#include <stack>

using namespace std;


class Solution {

public:

	int longestValidParentheses(string s) {
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

};

int main(int argc, char** argv)
{
	Solution sl;
	string s(")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())");		
    int ret = sl.longestValidParentheses(s);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}