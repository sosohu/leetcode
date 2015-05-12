#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


class Solution {

public:
	bool scanNum(const string &str, int& num){
		if(str.size() == 1 && (str[0] == '+' || str[0] == '-' 
			|| str[0] == '*' || str[0] == '/') )
			return false;
		bool isMunis = false;
		if(str[0] == '-')	isMunis = true;
		num = 0;
		for(int i = 0; i < str.size(); i++)
			if(str[i] != '+' && str[i] != '-')
				num = num*10 + str[i] - '0';
		num = isMunis? -num : num;
		return true;
	}

	int evalRPN(vector<string>& tokens) {
		int result = 0, num = 0;
		if(tokens.size() == 0)	return 0;
		scanNum(tokens[0], num);
		if(tokens.size() <= 2)	return num;
		stack<int> s;
		s.push(num);
		scanNum(tokens[1], num);
		s.push(num);
		for(int i = 2; i < tokens.size(); i++){
			if(!scanNum(tokens[i], num)){
				int first = s.top(); s.pop();
				int second = s.top(); s.pop();
				switch(tokens[i][0]){
					case '+': s.push(second + first); break;
					case '-': s.push(second - first); break;
					case '*': s.push(second * first); break;
					case '/': s.push(second / first); break;
				}
			}else{
				s.push(num);
			}
		}
		result = s.top();
		return result;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<string> tokens{"-1","1","*","-1","+"};
	cout<<sl.evalRPN(tokens)<<endl;
	return 0;

}
