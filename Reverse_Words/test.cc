#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

    void reverseWords(string &s) {
		int len = s.length();
		vector<string> data;
		int i = 0 , j ;
		while(i < len){
			if(s[i] != ' ')
				break;
			i++;
		}
		j = i;
		for(; i < len; i++){
			if(s[i] == ' '){
				data.push_back(s.substr(j, i - j));
				while(i < len){
					if(s[i] != ' ')
						break;
					i++;
				}
				j = i;
			}
		}
        if(s[len - 1] != ' ')
				data.push_back(s.substr(j, i - j));
		s.erase();
		int last = data.size() - 1;
		if(last > -1)
			s.append(data[last]);
		for(i = last - 1; i > -1; i--){
			s.append(" ");
			s.append(data[i]);
		}
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("  hello my world ada");		
    sl.reverseWords(s);
	
	cout<<"Result  :("<<s<<")"<<endl;

	return 0;

}
