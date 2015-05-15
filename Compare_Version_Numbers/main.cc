#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class Solution {

public:

	int compareVersion(string version1, string version2) {
		int i = 0, j = 0, n1 = version1.size(), n2 = version2.size();
		if(n1 == 0 && n2 == 0)	return 0;
		if(n1 == 0 || n2 == 0)	
			return n1 == 0? compareVersion("0", version2) : compareVersion(version1, "0");
		while(i < n1 && version1[i] == '.')	i++;
		while(j < n2 && version2[j] == '.')	j++;
		if(i == n1 && j == n2)	return 0;
		if(i == n1 || j == n2)	return i == n1? -1 : 1;
		int ei = i, ej = j;
		while(ei < n1 && version1[ei] != '.')	ei++;
		while(ej < n2 && version2[ej] != '.')	ej++;
		int v1 = atoi(version1.substr(i, ei - i).c_str());
		int v2 = atoi(version2.substr(j, ej - i).c_str());
		if(v1 == v2)
			 return compareVersion(version1.substr(ei, n1 - ei), version2.substr(ej, n2 - ej));
		if(v1 < v2)	return -1;
		else return 1;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.compareVersion("01.0","1")<<endl;

	return 0;

}
