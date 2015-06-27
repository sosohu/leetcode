#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int getNum(const string &s, int &pos){
		int num = 0;
		while(pos < s.size() && s[pos] == ' ')	pos++;
		while(pos < s.size() && s[pos] >= '0' && s[pos] <= '9'){
			num = num*10 + s[pos] - '0';
			pos++;
		}
		while(pos < s.size() && s[pos] == ' ')	pos++;
		return num;
	}

	int math(int a, int b, char op){
		switch(op){
			case '+':	return a+b;
			case '-':	return a-b;
			case '*':	return a*b;
			case '/':	return a/b;
		}
	}

	int opMulDiv(const string &s, int &pos, int cur){
		char op;
		int next;
		do{
			op = s[pos++];
			next = getNum(s, pos);
			cur = math(cur, next, op);
		}while(pos < s.size() && (s[pos] == '*' || s[pos] == '/'));
		return cur;
	}

	int calculate(string s){
		int pos = 0, num = getNum(s, pos), cur = 0;
		char op;
		if(pos == s.size())	return num;
		while(pos < s.size()){
			op = s[pos];
			if(op == '+' || op == '-'){
				cur = getNum(s, ++pos);
				if(pos == s.size() || s[pos] == '+' || s[pos] == '-')
					num = math(num, cur, op);
				else	num = math(num, opMulDiv(s, pos, cur) , op);				
			}else{
				num = opMulDiv(s, pos, num);
			}
		}
		return num;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.calculate("1*2-3/4+5*6-7*8+9/10")<<endl;

	return 0;

}
