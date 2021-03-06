#include <iostream>
#include <string>
#include <stack>

using namespace std;


class Solution {

public:

	bool isValid_1st(string s) {
		stack<int> data;
		int len = s.length();
		for(int i = 0; i < len; i++){
			switch(s[i]){
				case '(': data.push(0); break;
				case '[': data.push(1); break;
				case '{': data.push(2); break;
				case ')': if(data.empty() || data.top() != 0)	return false; data.pop(); break;
				case ']': if(data.empty() || data.top() != 1)	return false; data.pop(); break;
				case '}': if(data.empty() || data.top() != 2)	return false; data.pop(); break;
				default: return false;
			}
		}	
		if(!data.empty())	return false;
		return true;
    }

	bool isValid(string s) {
		stack<int> left; // 0,1,2 represent (, [, {
		for(int i = 0; i < s.size(); i++){
			switch(s[i]){
				case '(': left.push(0); break;
				case '[': left.push(1); break;
				case '{': left.push(2); break;
				case ')': if(left.empty() || left.top() != 0)	return false; left.pop(); break;
				case ']': if(left.empty() || left.top() != 1)	return false; left.pop(); break;
				case '}': if(left.empty() || left.top() != 2)	return false; left.pop(); break;
				default: return false;
			}
		}
		return left.empty();
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("{}][}}{[))){}{}){(}]))})[({");		

	bool ret = sl.isValid(s);	

	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
