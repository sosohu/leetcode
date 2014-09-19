#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;



void print(vector<vector<string> > data){
	int len = data.size();
	int size;
	cout<<endl<<endl<<"PRINT MSG"<<endl;
	for(int i = 0; i < len; i++){
		size = data[i].size();
		for(int j = 0; j < size; j++){
			cout<<data[i][j]<<" ";
		}
		cout<<endl;
	}
}

class Solution {

public:

	bool is_palindrome(string& s){
		int len = s.length();
		for(int i = 0; i < len / 2; i++){
			if(s[i] != s[len - 1 - i])
				return false;
		}
		return true;
	}

	int minCut(string s) {
		int len = s.length();
		if(is_palindrome(s))
			return 0;

		int data[len][len];
		map<string, int> find;

		
		for(int i = 0; i < len; i++){
			data[i][i] = 0;
			for(int j = i + 1; j < len; j++){
				data[i][j] = -1;
			}
		}

		int min = len ;
		int count;
		string str;
		for(int step = 2; step <= len; step++){
			find.clear();
			for(int i = 0; i <= len - step; i++){
				str = s.substr(i, step);
				if(find.count(str) != 1){
					if(is_palindrome(str)){
						data[i][i + step -1] = 0;
						find[str] = 0;
						continue;
					}
				}else{
					data[i][i + step -1] = find[str];
					continue;
				}
				min  = len;
				for(int j = i; j < i + step - 1; j++){
					if(data[i][j] != -1){
						count = data[i][j] + data[j+1][i + step - 1] + 1;		
						if(count < min)
							min = count;
					}
				}
				if(min != len){
					data[i][i+step-1] = min;
					find[str] = min;
				}
			}
		}
		return data[0][len - 1];		
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece");		
	//string s("ab");
	int ret;
	ret = sl.minCut(s);
	
	cout<<ret<<endl;

	//print(ret);
	
	return 0;

}
