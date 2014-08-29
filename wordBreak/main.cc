#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {

public:

	void	Init(const string& s ,vector<string>** data, 
				 const unordered_set<string>& dict, int n){
			string tmp;
			for(int i = 0; i < n; i++){
				tmp = s.substr(i,1);
				if(dict.count(tmp) == 1)
					data[i][i].push_back(tmp);
			}
	} 

	void defined_Op(vector<string>& data, const vector<string>& first,
					const vector<string>& second){
		if(first.empty() || second.empty())
			return ;
		string tmp;
		for(int i = 0; i < first.size(); i++){
			for(int j = 0; j < second.size(); j++){
				tmp = first[i];
				tmp.append(" ");
				tmp.append(second[j]);
				cout<<"tmp: "<<tmp<<endl;
				data.push_back(tmp);
			}
		}
	}

	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		int len = s.length();
		vector<string>** data = new vector<string>*[len];		
		for(int i = 0; i < len; i++){
			data[i] = new vector<string>[len];
		}
		
		Init(s,data,dict,len); // init data[i][i], step = 1
		string tmp;
		for(int step = 2; step <= len; step++){
			for(int i = 0; i <= len - step; i++){
				for(int j = i; j < i + step - 1; j++){
					defined_Op(data[i][i + step - 1], 
								data[i][j], data[j + 1][i + step - 1]);
				}
				tmp = s.substr(i,step);
				if(dict.count(tmp) == 1)
					data[i][i+step-1].push_back(tmp);
				cout<<tmp<<endl;
			}
		}

		vector<string> ret = data[0][len-1];
		
		for(int i = 0; i < len; i++){
			delete [] data[i]; 
		}
		delete [] data;
		return ret;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("catsanddog");		
	unordered_set<string> d({"cat", "cats", "and", "sand", "dog"});
	vector<string> ret = sl.wordBreak(s,d);
	
	cout<<"Result  :"<<endl;
	for(int i = 0; i < ret.size(); i++)
			cout<<ret[i];
	cout<<endl;

	return 0;

}
