#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

    bool isAnagram(string s, string t) {
        if(s.size() > t.size()) return isAnagram(t, s);
        vector<int> table(26, 0);
        for(int i = 0; i < s.size(); i++)
            table[s[i] - 'a']++;
        for(int i = 0; i < t.size(); i++)
            if(table[t[i] - 'a'] == 0)  return false;
            else    table[t[i] - 'a']--;
        return true;
    }

};

int main(int argc, char** argv)
{
	Solution sl;

	return 0;

}
