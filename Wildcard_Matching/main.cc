#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class Solution {

public:

	bool isMatch(const char *s, const char *p) {
		int len1 = strlen(s);
		int len2 = strlen(p);
		const char *p1 = s;
		const char *p2 = p;
		int pos1 = 0, pos2 = 0;
		
		bool ret = false;
		while(pos1 < len1 && pos2 < len2){
			if(p2[pos2] == '?'){
				pos1++;
				pos2++;
				continue;
			}
			if(p2[pos2] == '*'){
				if(pos2+1 < len2 && p2[pos2+1] == '*'){
					pos2++;
					continue;
				}
				pos2++;
				ret = ret || isMatch(p1+pos1, p2+pos2);		
				if(ret) return true;
				pos1++;
				pos2--;
				continue;
			}
			
			if(p1[pos1] != p2[pos2])
				return false;
			pos1++;
			pos2++;
		}

		if(pos1 == len1){
			while(pos2 < len2){
				if(p2[pos2] != '*')
					return ret;
				pos2++;
			}
			return true;
		}
		return ret;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	
    bool ret = sl.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b");
	//bool ret = sl.isMatch("hi","*?");
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
