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

	vector<vector<string> > partition_1st(string s) {
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

	void backtrack(vector<vector<string> > &result, vector<string> &track,
					vector<vector<bool> > &pal, string &s, int pos, int n){
		if(pos == n){
			result.push_back(track);
			return;
		}
		for(int j = pos; j < n; j++){
			if(pal[pos][j]){
				track.push_back(s.substr(pos, j - pos + 1));
				backtrack(result, track, pal, s, j+1, n);
				track.pop_back();
			}
		}
	}

	vector<vector<string> > partition(string s) {
		int n = s.size();
		vector<vector<string> > result;
		vector<string> track;
		vector<vector<bool> > pal(n, vector<bool>(n, false));
		for(int i = 0; i < n; i++){
			for(int j = 0; i - j >= 0 && i + j < n; j++){
				if(s[i-j] != s[i+j]) break;
				pal[i-j][i+j] = true;
			}
		}
		for(int i = 1; i < n; i++){
			for(int j = 1; i - j >= 0 && i + j <= n; j++){
				if(s[i-j] != s[i+j-1]) break;
				pal[i-j][i+j-1] = true;
			}
		}
		backtrack(result, track, pal, s, 0, n);
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("bb");		
    vector<vector<string> > ret = sl.partition(s);
	
	print(ret);
	
	return 0;

}
