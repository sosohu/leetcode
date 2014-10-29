#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	bool isMatch(const char *s, const char *p) {
		const char *ps, *pp, *star = NULL, *lasts;
		ps = s;
		pp = p;
		while(*ps != '\0' && *pp != '\0'){
			if(*pp != '*' && *pp != '.'){
				if(*ps != *pp){
					if(star != NULL){
						ps = ++lasts;
						pp = star + 1;
					}else{
						return false;
					}
				}else{
					ps++;
					pp++;
					continue;
				}
			}else{
				if(*pp == '.'){
					ps++;
					pp++;
				}else{
					while(*(pp+1) != '\0' && *(pp+1) == '*'){
						pp++;
					}
					if(*(pp+1) == '\0')	return true;
					lasts = ps;
					star = pp;
					pp++;
				}	
			}
		}
		if(*ps == '\0'){
			while(*pp != '\0' & *pp == '*'){
				pp++;
			}
			if(*pp != '\0')	return false;
			else	return true;
		}
		return false;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	const char *s1 = "aaaaaaaadppffcadad";		
	const char *s2 = "aaa**ad**ff.adad";		
    int ret = sl.isMatch(s1, s2);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
