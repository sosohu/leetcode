#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	char *strStr(char *haystack, char *needle) {
		char *p, *p1, *p2;
		p = haystack;

		if(*needle != '\0')	return haystack;

		while(*p != '\0'){
			p2 = needle;
			p1 = p;
			while(*p1 != '\0' && *p2 != '\0'){
				if(*p1 != *p2)	break;
				p1++;
				p2++;
			}
			if(*p2 == '\0')	return p;
			if(*p1 == '\0')	break;
			p++;
		}
		return NULL;
    }

	/*
	void setNext(vector<int> &next, const char* chr){
		int size = next.size();
		if(size == 1)	return;
		const char* p = chr;
		p++;
		if(*p == *chr) next[1] = 1;
		else	next[1] = 0;

		p++;
		int pos = 2;
		while(*p){
			int k = next[pos - 1];
			if(*p == *(chr + k + 1))
				next[pos] = next[pos - 1] + 1;
			else
				next[pos] = 0;
		}		
	}

	//KMP
	char *strStr(char *haystack, char *needle) {
		int  len = strlen(needle);
		vector<int> next(len, -1);
		setNext(next, needle);
	}
	*/

};

int main(int argc, char** argv)
{
	Solution sl;
	char s[] = "hellomyworlda";		
	char t[] = "worlda";		
    char* ret = sl.strStr(s, t);

	cout<<ret<<endl;	

	cout<<endl;

	return 0;

}
