#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	int minDistance(string word1, string word2) {	
		int len1 = word1.length();
		int len2 = word2.length();
		vector<vector<int> > data(len1+1, vector<int>(len2+1, 0));

		for(int i = 0; i < len1 + 1; i++)
			data[i][0] = i;
		for(int j = 0; j < len2 + 1; j++)
			data[0][j] = j;

		for(int i = 1; i < len1 + 1; i++){
			for(int j = 1; j < len2 + 1; j++){
				if(word1[i - 1] == word2[j - 1])
					data[i][j] = data[i-1][j-1];
				else{
					data[i][j] = data[i-1][j] < data[i][j-1]? data[i-1][j]:data[i][j-1];
					if(data[i][j] > data[i-1][j-1])
						data[i][j] = data[i-1][j-1];
					data[i][j]++;
				}
			}
		}
		return data[len1][len2];
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	string s1("catk"), s2("attk");
	int ret = sl.minDistance(s1, s2);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
