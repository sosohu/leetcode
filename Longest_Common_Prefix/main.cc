#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	string longestCommonPrefix(vector<string> &strs) {
		int size = strs.size();
		string str;
		if(size == 0)	return str;
		bool done = false;
		vector<int>	pos(size, 0);
		vector<int>	length(size, 0);
		for(int i = 0; i < size; i++){
			length[i] = strs[i].length();
		}
		int count = 0;
		while(1){
			for(int i = 0; i < size; i++){
				if(pos[i]++ == length[i]){
					done = true;
					break;
				}
			}
			if(done)	break;
			char cur = strs[0][count];
			for(int i = 1; i < size; i++){
				if(strs[i][count] != cur){
					done = true;
					break;
				}
			}	
			if(done)	break;
			count++;
		}
		str = strs[0].substr(0, count);
		return str;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<string> data{"abca", "abc"};
	string ret = sl.longestCommonPrefix(data);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
