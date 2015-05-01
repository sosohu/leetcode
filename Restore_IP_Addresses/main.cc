#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;


class Solution {

public:

	// assert s.length() == 3
	inline bool isIp(string& s){
		assert(s.length() == 3);	
		if(s[0] == '1')	return true;
		if(s[0] == '2' && s[1] <= '4' && s[1] >= '0')	return true;
		if(s[0] == '2' && s[1] == '5' && s[2] >= '0' && s[2] <= '5')	return true;
		return false;
	}

	vector<string> recursion(string& s, int len, int n){
		vector<string> data;
		if(len > 3*n || len < n)	return data;

		vector<string> tmp;
		string str[3];
		for(int i = 0; i < 3; i++){
			if(len-1-i >= 0)
				str[i] = s.substr(len-1-i, i+1);
		}

		tmp = recursion(s, len-1, n-1);
		if(len-1 == 0 && n-1 == 0){
			data.push_back(str[0]);
		}else{
			for(int i = 0; i < tmp.size(); i++)
				tmp[i] = tmp[i] + "." + str[0];
			data.insert(data.end(), tmp.begin(), tmp.end());
		}
		
		if(len >= 2){
			tmp.clear();
			if(s[len-2] != '0'){
				tmp = recursion(s, len-2, n-1);
				if(len-2 == 0 && n-1 == 0){
					data.push_back(str[1]);
				}else{
					for(int i = 0; i < tmp.size(); i++)
						tmp[i] = tmp[i] + "." + str[1];
					data.insert(data.end(), tmp.begin(), tmp.end());
				}
			}
		}
	
		if(len >= 3){
			tmp.clear();
			if(isIp(str[2])){
				tmp = recursion(s, len-3, n-1);
				if(len-3 == 0 && n-1 == 0)
					data.push_back(str[2]);
				else{
					for(int i = 0; i < tmp.size(); i++)
						tmp[i] = tmp[i] + "." + str[2];
					data.insert(data.end(), tmp.begin(), tmp.end());
				}
			}
		}
		return data;
	}

	vector<string> restoreIpAddresses_1st(string s) {
		return recursion(s, s.length(), 4);	
    }

	int getCon(string &s, int pos, int len){
		if(s[pos] == '0' || pos+1 == len)	return 1;
		if(pos+2 == len)	return 2;
		string substr = s.substr(pos, 3);
		if(substr.compare("256") < 0)	return 3;
		return 2;
	}

	void backtrack(vector<string> &result, string &track, string &s,
					int pos, int len, int count, int n){
		if(count == n && pos == len){
			result.push_back(track);
			return;
		}
		if(count == n || pos == len) return;
		int con = getCon(s, pos, len);
		string tmp = track;
		for(int i = 1; i <= con; i++){
			track = tmp + (tmp.empty()? "" : ".") + s.substr(pos, i);
			backtrack(result, track, s, pos+i, len, count+1, n);
		}
		track = tmp;
	}

	vector<string> restoreIpAddresses(string s) {
		int n = s.length();
		vector<string> result;	
		string track;
		backtrack(result, track, s, 0, n, 0, 4);
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("000256");		
	vector<string> ret = sl.restoreIpAddresses(s);
	
	for(int i = 0; i < ret.size(); i++)
		cout<<ret[i]<<endl;

	return 0;

}
