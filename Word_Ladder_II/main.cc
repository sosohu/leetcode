#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;


class Solution {

public:

void Trace(vector<int>& trace, vector<string>& data, int pos, vector<vector<string> >& path){
		vector<string> tmp, vec;
		while(pos != 0){
			tmp.push_back(data[pos]);
			pos = trace[pos];
		}
		tmp.push_back(data[0]);
		for(int i = tmp.size() - 1; i >= 0; i--)
			vec.push_back(tmp[i]);
		path.push_back(vec);
	}

	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		int len = start.length();
		unordered_set<string> find;
		//unordered_set<string> bad;
		vector<string> data;
		vector<vector<string> > path;
		vector<int> trace;

		data.push_back(start);
		trace.push_back(0);
		find.insert(start);
		string str, tmp;
		int length = 0;
		int size;
		int pos = 0;
		bool this_level = false;
		while(size = data.size() - pos){
			unordered_set<string> local_find;
			for(int i = 0; i < size; i++){
				str = data[pos+i];
				if(str.compare(end) == 0){
					Trace(trace, data , pos+i, path);
					this_level = true;
					continue;
				}
				if(this_level)
					continue;
				for(int j = 0; j < len; j++){
				 	tmp = str;
					for(int k = 97; k < 123; k++){
						tmp[j] = k;
						if(dict.count(tmp) == 1 && find.count(tmp) == 0 ){
							data.push_back(tmp);
							trace.push_back(pos+i);
							if(local_find.count(tmp) == 0)
								local_find.insert(tmp);
						}
					}
				}
			}
			if(this_level)
				break;
			pos = pos + size;
			find.insert(local_find.begin(), local_find.end());
		}
		return path;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	unordered_set<string> dict;
	string data[] = {"miss","dusk","kiss","musk","tusk","diss","disk","sang","ties","muss"};
	for(int i = 0; i < 10; i++)
		dict.insert(data[i]);
    vector<vector<string> > ret = sl.findLadders("kiss", "tusk", dict);
	
	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}

	return 0;

}
