#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

      public:

	void Trace(string start, string str, vector<vector<string> >& path,
		   unordered_map<string, vector<string> >& father) {
		vector<string> vec;
		vec.push_back(str);
		path.push_back(vec);	
		string tmp;
		int len;
		bool ret = false;
		while(1){
			int size = path.size();
			for(int i = 0; i < size; i++){
				vec = path[i];
				tmp = vec.back();
				if(tmp.compare(start) == 0){
					ret = true;
					break;
				}
				vec.push_back(father[tmp][0]);
				path[i] = vec;
				len = vec.size();
				for(int j = 1; j < father[tmp].size(); j++){
					vec[len - 1] = father[tmp][j];
					path.push_back(vec);
				}
			}
			if(ret)
				break;
		}
		
		for(int i = 0; i < path.size(); i++)
			reverse(path[i].begin(), path[i].end());
	}

	 vector < vector < string > >findLadders(string start, string end,
						  unordered_set < string >
						  &dict) {
		int len = start.length();
		unordered_set < string > find;
		unordered_set < string > last;
		unordered_set < string > cur;
		vector < vector < string > > path;
		unordered_map < string, vector < string > >father;

		bool this_level = false;
		find.insert(start);
		last.insert(start);
		string str, tmp;
		while (!last.empty()) {

			cur.clear();
			for (auto iter = last.begin(); iter != last.end(); iter++) {

				str = *iter;

				for (int i = 0; i < len; i++) {
					tmp = str;
					for (int j = 97; j < 123; j++) {
						tmp[i] = j;
						if (tmp.compare(end) == 0){
							this_level = true;
							father[tmp].push_back(str);
						}else{
							if (dict.count(tmp) == 1 && find.count(tmp) == 0) {
								father[tmp].push_back(str);
								if(cur.count(tmp) == 0)
									cur.insert(tmp);
							}
						}
					}
				}
			}
			if(this_level){
				//path = Trace(start, end, father);
				Trace(start, end, path, father);
				return path;
			}
			find.insert(cur.begin(), cur.end());
			last.swap(cur);
		}
		
		return path;
	}

};

int main(int argc, char **argv)
{
	Solution sl;
	unordered_set < string > dict;
	string data[] =
	    { "hot","dot","dog","lot","log" };
	for (int i = 0; i < 5; i++)
		dict.insert(data[i]);
	vector < vector < string > >ret = sl.findLadders("hit", "cog", dict);

	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++)
			cout << ret[i][j] << " ";
		cout << endl;
	}

	return 0;

}
