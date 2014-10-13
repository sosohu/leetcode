#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	int numDecodings(string s) {
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

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("12");		
	int ret = sl.numDecodings(s);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
