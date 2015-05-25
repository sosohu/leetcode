#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {

public:

	int longestConsecutive_1st(vector<int> &num) {
		unordered_map<int,bool> used;
		const int size = num.size();
		for(int i = 0; i < size; i++)
			used[num[i]] = false;

		int length = 0;
		for(int i = 0; i <	size; i++){
			if(used[num[i]])
				continue;
			int sub_len = 1;
			int tmp = num[i];
			while(1){
				tmp++;
				if(used.count(tmp) == 0)
					break;
				used[tmp] = true;
				sub_len++;
			}
			tmp = num[i];
			while(1){
				tmp--;
				if(used.count(tmp) == 0)
					break;
				used[tmp] = true;
				sub_len++;
			}
			if(length < sub_len)
				length = sub_len;
		}
		return length;
    }

	int longestConsecutive(vector<int> &num) {
		unordered_set<int> table;
		for(int i = 0; i < num.size(); i++)
			table.insert(num[i]);
		unordered_set<int> used;
		int ret = 0;
		for(int i = 0; i < num.size(); i++){
			if(used.count(num[i]) == 0){
				used.insert(num[i]);
				int con = 1;
				for(int j = 1; ; j++){
					if(table.count(num[i] + j) == 0)	break;
					con++;
					used.insert(num[i] + j);	
				}
				for(int j = 1; ; j++){
					if(table.count(num[i] - j) == 0)	break;
					con++;
					used.insert(num[i] - j);	
				}
				if(ret < con)	ret = con;
			}
		}
		return ret;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> data;
	
	int a[6] = {200,1,400,4,3,2};	
	
	for(int i = 0; i < 6; i++)
		data.push_back(a[i]);

    int ret = sl.longestConsecutive(data);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
