#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
		istringstream iss(str);
		string cur, table[27];
		int i = 0;
		unordered_set<string> used;
		if(pattern.size() == 0)  return false;
		while(iss>>cur && i < pattern.size()){
		    int index = pattern[i] != ' '? pattern[i] - 'a' : 26;
			if(table[index].size() == 0){
				if(used.count(cur))	return false;
				table[index] = cur;
				used.insert(cur);
			}else if(table[index] != cur){
				return false;
			}
			i++;
		}
		if(iss >> cur  || i < pattern.size())	return false;
		return true;
    }
};

int main(int argc, char** argv)
{
	Solution sl;
	string pattern = "b b a a a c e";
	string str = "b b b a a c e f";
	cout<<sl.wordPattern(pattern, str)<<endl;
	return 0;

}
