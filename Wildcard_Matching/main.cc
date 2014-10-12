#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;


class Solution {

public:

	bool isMatch(const char *s, const char *p){
		int len1 = strlen(s);
		int len2 = strlen(p);
		const char* p1 = s;
		const char* p2 = s;

		if(len2 == 0 && len1 != 0)	return false;
		if(len1 == 0){
			for(int i = 0; i < len2; i++)	
				if(p2[i] != '*') return false;
			return true;
		}

		vector<vector<bool> > data(len1, vector<bool>(len2, false));

		if(p2[0] == '*'){
			for(int i = 0; i < len1; i++)
				data[i][0] = true;
		}else{
			if(p2[0] == '?'){
				data[0][0] = true;
				for(int i = 1; i < len1; i++)
					data[i][0] = false;
			}
			else{
				for(int i = 0; i < len1; i++)
					data[i][0] = false;
				if(p1[0] == p2[0])
					data[0][0] = true;
			}
		}

		for(int j = 1;  j < len2; j++){
			switch(p2[j]){
				case '*': data[0][j] = true; break;
				case '?': ;
				default: data[0][j] = false;
			}
		}

		int part = false;;
		for(int j = 1; j < len2; j++){
			for(int i = 1; i < len1; i++){
				// assgin data[i][j] 
				switch(p2[j]){
					case '?': data[i][j] = data[i-1][j-1]; break;
					case '*':   part = false;
								for(int k = i; k >= 0; k--){
									part = part || data[k][j-1];			
								}
								data[i][j] = part; break;
					default: data[i][j] = p1[i] == p2[j] && data[i-1][j-1];
				}
			}
		}
		return data[len1-1][len2-1];
	}

	/*
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
    }*/

};

int main(int argc, char** argv)
{
	Solution sl;
	
    //bool ret = sl.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b");
	bool ret = sl.isMatch("hia","*?a");
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
