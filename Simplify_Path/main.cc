#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


class Solution {

public:

	vector<string> split(string& str){
		vector<string> data;
		int len = str.length();
		int i = 0;
		while(str[i] == '/'){
			i++;
		}
		int start, end;
		while(i < len){
			start = i;
			while(i < len && str[i] != '/'){
				i++;
			}
			data.push_back(str.substr(start, i - start));
			while(i < len && str[i] == '/'){
				i++;
			}
		}
		return data;
	}

	string simplifyPath(string path) {
		stack<string> s, tmp;
		vector<string> data = split(path);
		for(int i = 0; i < data.size(); i++){
			if(data[i].compare(".") == 0)
				continue;
			if(data[i].compare("..") == 0){
				if(!s.empty()){
					s.pop();
				}
				continue;
			}
			s.push(data[i]);
		}
		while(!s.empty()){
			tmp.push(s.top());
			s.pop();
		}
		if(tmp.empty()) return "/";
		string ret;
		while(!tmp.empty()){
			ret = ret + "/";
			ret = ret + tmp.top();
			tmp.pop();
		}
		return ret;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("/home/sosohu/huqinghai/leetcode/Simplify_Path/../.././");		
	string ret = sl.simplifyPath(s);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
