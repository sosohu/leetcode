#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	int numDecodings_1st(string s) {
		int len = s.length();
		if(len == 0)	return 0;
	
		vector<int> data(len+1, 0);
		data[0] = 1;
		if(s[0] != '0')
			data[1] = 1;

		for(int i = 2; i <= len; i++){
			if(s[i-1] != '0')
				data[i] = data[i-1];
			if(s[i-2] == '1')	data[i] = data[i] + data[i-2];
			if(s[i-2] == '2' && s[i-1] <= '6' && s[i-1] >= '0')
				data[i] = data[i] + data[i-2];
		}
		return data[len];
    }

	bool isValid(string &s){
		int size = s.size();
		int dfa[4][10] = {
			{3,1,1,2,2,2,2,2,2,2},
			{0,1,1,2,2,2,2,2,2,2},
			{3,1,1,2,2,2,2,2,2,2},
			{3,3,3,3,3,3,3,3,3,3}
		};
		int status = 0;
		for(int i = 0; i < size; i++)
			status = dfa[status][s[i]-'0'];
		return status != 3;
	}

	int numDecodings(string s) {
		int size = s.size();
		if(size == 0 || s[0] == '0' || !isValid(s))	return 0;
		vector<int> dp(size+1, 1);
		for(int i = 1; i < size; i++){
			if(s[i] == '0')
				dp[i+1] = dp[i-1];
			else
				if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
					dp[i+1] = dp[i] + dp[i-1];
				else
					dp[i+1] = dp[i];
		}
		return dp[size];
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("12");		
	int ret = sl.numDecodings(s);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
