#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {

public:

	int evalRPN(vector<string> &tokens) {	
		vector<int> store;
		for(int i = 0; i < tokens.size(); i++){
			if(tokens[i].length() > 1){
				if(tokens[i][0] == '-'){
						store.push_back(-atoi((tokens[i].substr(1).c_str())));
					continue;
				}
				if(tokens[i][0] == '+'){
					store.push_back(atoi((tokens[i].substr(1)).c_str()));
					continue;
				}
			}

			switch(tokens[i][0]){
				case '+': store[store.size() - 2] = store[store.size() - 2] 
							+ store[store.size() - 1]; 
						  store.pop_back(); break;
				case '-': store[store.size() - 2] = store[store.size() - 2] 
							- store[store.size() - 1]; 
						  store.pop_back(); break;
				case '*': store[store.size() - 2] = store[store.size() - 2] 
							* store[store.size() - 1]; 
						  store.pop_back(); break;
				case '/': store[store.size() - 2] = store[store.size() - 2] 
							/ store[store.size() - 1]; 
						  store.pop_back(); break;
				default: store.push_back(atoi(tokens[i].c_str()));
			}
		}
		return store[0];
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	//string tmp[] = {"4", "13", "5", "/", "+"};
	//string tmp[] = {"-2", "1", "+", "3", "*"};
	string tmp[] = {"3", "-4", "+"};
	vector<string> s;
	for(int i = 0; i < 3; i++)
		s.push_back(tmp[i]);
    int ret = sl.evalRPN(s);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
