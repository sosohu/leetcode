#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

	typedef struct node{
		string key;
		int val;
	} node;

	class alpthsort{
	public:
		bool operator()(char i, char j){
			return i < j;
		}
	} alpthsort;

	class nodesort{
	public:
		bool operator()(node i, node j){
			return i.key.compare(j.key) < 0;
		}
	} nodesort;


public:

	vector<string> anagrams(vector<string> &strs) {
		vector<string> ret;
		int size = strs.size();
		vector<node> data(size, node());

		for(int i = 0; i < size; i++){
			data[i].key = strs[i];
			sort(data[i].key.begin(), data[i].key.end(), alpthsort);
			data[i].val = i;
		}

		sort(data.begin(), data.end(), nodesort);

		string last = data[0].key;
		bool first = true;
		for(int i = 1; i < size; i++){
			if(last.compare(data[i].key) == 0){
				if(first){
					ret.push_back(strs[data[i-1].val]);
					first = false;
				}
				ret.push_back(strs[data[i].val]);
			}else{
				last = data[i].key;
				first = true;
			}
		}
		
		return ret;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<string> str(5, "");
	str[0] = "ada";
	str[2] = "aad";
	str[1] = "adada";
	str[3] = "adada";
    vector<string> ret = sl.anagrams(str);
	
	for(int i = 0; i < ret.size(); i++){
		cout<<ret[i]<<endl;
	}

	return 0;

}
