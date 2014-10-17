#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	string countAndSay(int n) {
		if(n == 0)	return "";
		vector<int> last;
		vector<int> cur;
		last.push_back(1);
		for(int i = 1; i < n; i++){
			cur.clear();
			int pos = 1;
			int last_one = last[0];
			int count_one = 1;
			while(pos < last.size()){
				if(last[pos] != last_one){
					cur.push_back(count_one);
					cur.push_back(last_one);
					count_one = 1;
					last_one = last[pos];
				}else{
					count_one++;	
				}
				pos++;
			}
			cur.push_back(count_one);
			cur.push_back(last_one);
			last = cur;
		}
		
		string str;
		for(int i = 0; i < cur.size(); i++){
			switch(cur[i]){
				case 0: str = str + "0"; break;
				case 1: str = str + "1"; break;
				case 2: str = str + "2"; break;
				case 3: str = str + "3"; break;
				case 4: str = str + "4"; break;
				case 5: str = str + "5"; break;
				case 6: str = str + "6"; break;
				case 7: str = str + "7"; break;
				case 8: str = str + "8"; break;
				case 9: str = str + "9"; break;
				default: ;
			}
		}
		return str;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
    string ret = sl.countAndSay(5);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
