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

	void define_op(vector<vector<string> >& data, string& str, vector<vector<string> >& rhs){
		int len = rhs.size();
		vector<string> tmp;
		/*
		if(len == 0){
			tmp.push_back(str);
			data.push_back(tmp);
			return;
		}
		*/
		for(int i = 0; i < len; i++){
			tmp = rhs[i];
			tmp.push_back(str);
			data.push_back(tmp);
		}
	}

	inline void Init(map<string, vector<vector<string> > >& data, 
					 map<string, bool>& palind,string& s, int n){
		for(int i = 0; i < n; i++){
			string str(s,i,1);
			if(data.count(str) == 0){
				vector<string> tmp;
				tmp.push_back(str);
				data[str].push_back(tmp);
				palind[str] = true;
			}
		}
	}

	vector<vector<string> > partition(string s) {
		int len = s.length();
		map<string, vector<vector<string> > > data;
		map<string, bool> is_palind;
		Init(data, is_palind, s, len);
		string val,str,rhs;
		vector<string> tmp;
		for(int step = 2; step <= len; step++){
			for(int i = 0; i < len - step + 1; i++){
				val = s.substr(i, step);
				if(data.count(val) == 1)
					continue;
				for(int j = i + step -1; j > i; j--){
					str = s.substr(j, i +  step - j );
					rhs = s.substr(i, j - i);
					if(is_palind.count(str) == 1){
						define_op(data[val], str, data[rhs]);	
					}
				}
				if(is_palind.count(val) == 1 || is_palindrome(val)){
					tmp.clear();
					tmp.push_back(val);
					data[val].push_back(tmp);
					is_palind[val] = true;
				}
			}
		}
		return data[s];
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
