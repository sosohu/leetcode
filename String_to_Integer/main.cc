#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int atoi(const char *str) {
		const char *p = str;
		bool has_sign = false;
		bool minis = false;
		int sum = 0;
		int IN_MAX = 2147483647;
		int IN_MIN = -2147483648; 
		while(*p != '\0' && *p != '+' && *p != '-' && (*p < '0' || *p > '9')){
		    if(*p != ' ')   return 
			p++;
		}
		if(*p == '\0')	return 0;
		while(*p != '\0'){
			if(*p == '+'){
				if(has_sign)	return false;
				has_sign = true;
				p++;
				continue;
			}
			if(*p == '-'){
				if(has_sign)	return false;
				has_sign = true;
				minis = true;
				p++;
				continue;
			}
			if(*p != '\0' && *p != '+' && *p != '-' && (*p < '0' || *p > '9')){
				break;
			}
			// judge the overflow
			if(sum > 214748364){
				if(minis)
					return IN_MIN;
				else
					return IN_MAX;
			}
			if(minis && sum == 214748364){
				if(*p == '9')	return IN_MIN;
				if(*p == '8')	return IN_MIN;
			}
			if(!minis && sum == 214748364){
				if(*p == '9' || *p == '8')	return IN_MAX;
			}
			sum = sum * 10 + ((*p) - '0');
			p++;
			//if(*p == '\0')	return sum;
		}
		if(minis)	sum = -sum;
		return sum;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	const char *s = "  -0012a42";		
	int ret = sl.atoi(s);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
