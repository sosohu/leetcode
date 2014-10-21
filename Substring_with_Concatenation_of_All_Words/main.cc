#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {

public:

	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> data;
		if(L.size() == 0)	return data;
		int len = S.length();
		unordered_map<string, int> SL;
		for(int i = 0; i < L.size(); i++){
			if(SL.count(L[i]) == 0)
				SL[L[i]] = 1;
			else
				SL[L[i]]++;
		}
		int l = L[0].length();
		if(len < l*L.size())	return data;
		unordered_map<string, int> Tmp;
		string str;
		unordered_set<int> LL;
		for(int i = 0; i <= len - l*L.size(); i++){
			if( i >= l && S.substr(i - l , l).compare(S.substr(i + l*L.size() - l, l)) == 0){
				if(LL.count(i - l) == 1){
					data.push_back(i);
					LL.insert(LL.end(), i);
				}
				if(LL.count(i - l) == 1)
					LL.erase(i - l);
				continue;
			}
			int j;
			Tmp = SL;
			for(j = 0; j < L.size(); j++){
				str = S.substr(i + l*j, l);
				if(Tmp.count(str) == 1 && Tmp[str] > 0){
					Tmp[str]--;
				}else{
					break;
				}
			}
			if(j == L.size()){
				data.push_back(i);
				LL.insert(LL.end(), i);
			}
			if(i - l >= 0 && LL.count(i - l) == 1)
				LL.erase(i - l);
		}
		return data;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	string S("barfoothefoobarman");
	vector<string> L(2, "");
	L[0] = "foo";
	L[1] = "bar";

	vector<int> ret = sl.findSubstring(S, L);
	
	for(int i = 0; i < ret.size(); i++)
		cout<<ret[i]<<" ";
	cout<<endl;

	return 0;

}
