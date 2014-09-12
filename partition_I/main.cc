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
		if(len == 0){
			tmp.push_back(str);
			data.push_back(tmp);
			return;
		}
		for(int i = 0; i < len; i++){
			tmp = rhs[i];
			tmp.push_back(str);
			data.push_back(tmp);
		}
	}

	vector<vector<string> > partition(string s) {
		int len = s.length();
		bool is_palind[len][len];
		vector<vector<string> > data[len][len];
		//map<string, vector<vector<string> > > data;
		{
			vector<string> tmp;
			string str = "0";
			tmp.push_back(str);
			for(int i = 0; i < len; i++){
				str[0] = s[i];
				tmp[0] = str;
				data[i][i].push_back(tmp);
				is_palind[i][i] = true;
			}
		}
		string str;
		vector<string> tmp;
		for(int step = 2; step <= len; step++){
			for(int i = 0; i < len - step + 1; i++){
				for(int j = i + step -1; j > i; j--){
					str = s.substr(j, i +  step - j );
					if(is_palind[j][i + step -1])
						define_op(data[i][i + step -1], str, data[i][j - 1]);	
				}
				str = s.substr(i, step);
				if(is_palindrome(str)){
					is_palind[i][i + step - 1] = true;
					tmp.clear();
					tmp.push_back(str);
					data[i][i + step -1].push_back(tmp);
				}else{
					is_palind[i][i + step - 1] = false;
				}
			}
		}
		return data[0][len-1];
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("aaaaadad");		
    vector<vector<string> > ret = sl.partition(s);
	
	print(ret);
	
	return 0;

}
