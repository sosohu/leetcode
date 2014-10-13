#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {

public:

	int longestConsecutive(vector<int> &num) {
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
