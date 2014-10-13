#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;


class Solution {

public:

	void	Init(const string& s , map<string, vector<string> >& data, 
				 const unordered_set<string>& dict, int n){
			string tmp;
			vector<string> vec_tmp;
			for(int i = 0; i < n; i++){
				tmp = s.substr(i,1);
				vec_tmp.clear();
				if(dict.count(tmp) == 1){
					vec_tmp.push_back(tmp);
				}
				data[tmp]= vec_tmp;
			}
	} 

	inline void defined_Op(vector<string>& data, const string& first,
					const vector<string>& second){
		if(second.empty())
			return ;
		string tmp;
		for(int j = 0; j < second.size(); j++){
			tmp = first;
			tmp.append(" ");
			tmp.append(second[j]);
			data.push_back(tmp);
		}
	}

	int longest(unordered_set<string> &dict){
		unordered_set<string>::iterator iter;
		int max = 0;
		for(iter = dict.begin(); iter != dict.end(); iter++){
			if(iter->length() > max)
				max = iter->length();
		}
		return max;
	}

	bool wordBreak_one(string s, unordered_set<string> &dict) {
		int len = s.length();
		if(len == 0)
			return false;
		bool data[len][len];
		string tmp;
		for(int i = 0; i < len; i++){
			tmp = s.substr(i,1);
			if(dict.count(tmp) == 1)
				data[i][i] = true;
			else
				data[i][i] = false;
		}
		for(int step = 2; step <= len; step++){
			for(int i = 0; i <= len - step; i++){
				tmp = s.substr(i, step);
				data[i][i+step-1] = false;
				for(int j = i; j < i + step - 1; j++){
					if(data[i][j] && data[j+1][i+step-1]){
						data[i][i+step-1] = true;
						break;
					}
				}
				if(dict.count(tmp) == 1){
					data[i][i+step-1] = true;
				}
			}
		}
		//cout<<data[0][len-1]<<endl;
		return data[0][len-1];
	}

	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		int len = s.length();
		vector<string> ret;
		if(len == 0)
			return ret;
		if(!wordBreak_one(s,dict))
			return ret;

		map<string, vector<string> > data;
		
		Init(s,data,dict,len); // init data[i][i], step = 1
		string tmp,done,left;
		vector<string> vec_tmp;
		for(int step = 2; step <= len; step++){
			for(int i = 0; i <= len - step; i++){
				tmp = s.substr(i, step);
				if(data.count(tmp) == 1){
					continue;
				}
				vec_tmp.clear();
				for(int j = i; j < i + step - 1; j++){
					done = s.substr(i, j - i + 1);
					if(dict.count(done) == 1){
						left = s.substr(j + 1, i + step - j -1);
						defined_Op(vec_tmp, done, data[left]);
					}
				}
				if(dict.count(tmp) == 1){
					vec_tmp.push_back(tmp);
				}
				data[tmp] = vec_tmp;
			}
		}
		
		ret = data[s];
		
		return ret;
	}

	/*
	vector<string> wordBreak_old(string s, unordered_set<string> &dict) {
		int len = s.length();
		vector<string>** data = new vector<string>*[len];		
		for(int i = 0; i < len; i++){
			data[i] = new vector<string>[len];
		}
		
		Init(s,data,dict,len); // init data[i][i], step = 1
		string tmp;
		unordered_map<string, int> has_count;
		cout<<"size: "<<len<<" "<<len<<" "<<len<<endl;
		for(int step = 2; step <= len; step++){
				has_count.clear();
			for(int i = 0; i <= len - step; i++){
				tmp = s.substr(i, step);
				if(has_count.count(tmp) == 1){
					int last = has_count[tmp];
					data[i][i + step -1] = data[last][last + step -1];
					continue;
				}
				has_count[tmp] = i;
				for(int j = i; j < i + step - 1; j++){
					tmp = s.substr(i, j - i + 1);
					if(dict.count(tmp) == 1){
						defined_Op(data[i][i + step - 1], 
								tmp, data[j + 1][i + step - 1]);
					}
				}
				tmp = s.substr(i,step);
				if(dict.count(tmp) == 1)
					data[i][i+step-1].push_back(tmp);
			}
		}

		vector<string> ret = data[0][len-1];
		
		for(int i = 0; i < len; i++){
			delete [] data[i]; 
		}
		delete [] data;
		return ret;
	}
	*/

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("a");
	//string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
	//unordered_set<string> d({"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"});
	unordered_set<string> d({"a"});
	//unordered_set<string> d({"a"});
	//vector<string> ret = sl.wordBreak_n2(s,d);
	/*
	bool ret = sl.wordBreak_one(s,d);
	if(ret)
		cout<<"ture"<<endl;
	else
		cout<<"false"<<endl;
	*/
	vector<string> ret = sl.wordBreak(s,d);
	
	cout<<"Result  :"<<endl;
	for(int i = 0; i < ret.size(); i++)
			cout<<ret[i]<<endl;

	return 0;

}
