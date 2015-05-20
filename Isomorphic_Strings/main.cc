#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:

	bool isIsomorphic(string s, string t) {
    	vector<int> table(256, -1), used(256, false);
		for(int i = 0; i < s.size(); i++){
			if(table[(unsigned int)s[i]] == -1){
				if(used[(unsigned int)t[i]])	return false;
				used[(unsigned int)t[i]] = true;
				table[(unsigned int)s[i]] = (unsigned int)t[i];
			}
			if(table[(unsigned int)s[i]] != (unsigned int)t[i])
				return false;
		}
		return true;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.isIsomorphic("ba", "aa")<<endl;

	return 0;

}
