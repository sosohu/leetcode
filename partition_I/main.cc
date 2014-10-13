#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

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

	vector<vector<string> > partition(string s) {
		int len = s.length();
		string str, left;
		vector<vector<string> > tmp;
		vector<vector<string> > ret;
		
		for(int i = 1; i < len ; i++){
			str = s.substr(len - i, i);
			if(is_palindrome(str)){
				left = s.substr(0, len - i);
				tmp = partition(left);
				int size = tmp.size();
				for(int j = 0; j < size; j++){
					tmp[j].push_back(str);
					ret.push_back(tmp[j]);
				}
					
			}
		}

		if(is_palindrome(s)){
			vector<string> vec;
			vec.push_back(s);
			ret.push_back(vec);
		}

		return ret;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("aaa");		
    vector<vector<string> > ret = sl.partition(s);
	
	print(ret);
	
	return 0;

}
