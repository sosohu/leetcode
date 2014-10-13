#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;


class Solution {

public:

	inline string get_str(int i){
		string str;
		switch(i){
			case 0: str = "0"; break;
			case 1: str = "1"; break;
			case 2: str = "2"; break;
			case 3: str = "3"; break;
			case 4: str = "4"; break;
			case 5: str = "5"; break;
			case 6: str = "6"; break;
			case 7: str = "7"; break;
			case 8: str = "8"; break;
			case 9: str = "9"; break;
			default:;
		}
		return str;
	}

	inline void get(int index, unordered_set<int> &used, string& ret, int n){
		int pos = -1;
		for(int i = 1; i <= n; i++){
			if(used.count(i) == 0){
				pos++;
				if(pos == index){
					string str = get_str(i);
					ret = ret + str;
					used.insert(i);
					return;
				}
			}
		}
	}

	string getPermutation(int n, int k) {
		vector<int> factorial(n+1, 1);
		if(k == 0)
			return "";
		for(int i = 2; i <= n; i++)
			factorial[i] = factorial[i-1]*i;
		unordered_set<int> used;
		string ret;
		
		for(int i = n-1; i >= 1; i--){
			int index = k/factorial[i];
			if(index*factorial[i] == k)
				index--;
			get(index, used, ret, n);
			k = k - index*factorial[i];
		}
		get(0, used, ret, n);
		return ret;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	string ret = sl.getPermutation(3, 6);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
