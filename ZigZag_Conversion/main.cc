#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	string convert(string s, int nRows) {
		int size = s.length();
		string str;
		if(size == 0)	return str;
		if(nRows == 1)	return s;
		int pos = 0;
		while(pos < size){
			str = str + s[pos];
			pos = pos + 2*(nRows - 1);
		}
		for(int i = 1; i < nRows - 1; i++){
			pos = i;
			while(pos < size){
				str = str + s[pos];
				pos = pos + 2*(nRows - 1 - i);
				if(pos < size){
					str = str + s[pos];
					pos = pos + 2*i;
				}else{
					break;
				}
			}
		}	
		pos = nRows - 1;
		while(pos < size){
			str = str + s[pos];
			pos = pos + 2*(nRows - 1);
		}
		return str;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("A");		

	string ret = sl.convert(s, 1);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
