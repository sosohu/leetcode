#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>

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

	 vector < vector < string > >findLadders_1st(string start, string end,
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

	void genTrack(vector<pair<string, int> > &tree, int pos, vector<string> &track){
		if(pos == 0){
			track.push_back(tree[0].first);
			return;
		}
		genTrack(tree, tree[pos].second, track);
		track.push_back(tree[pos].first);
	}

	/*多一丁点计算都会超时,多一丁点空间都会超空间......*/
	vector<vector<string> > findLadders(string start, string end,
						  				unordered_set<string> &dict){
		dict.insert(start);
		vector<vector<string> > result;
		vector<pair<string, int> > tree;
		unordered_map<string, int> used;
		used[start] = 0;
		tree.push_back(make_pair(start, -1));
		int last = 1, pre = -1, pos = 0;
		bool found = false;
		string cur, tmp;
		while(pos < last){
			cur = tree[pos].first;
			tmp = cur;
			for(int i = 0; i < cur.size(); i++){
				cur = tmp;
				for(int j = 'a'; j <= 'z'; j++){
					cur[i] = j;
					if(cur.compare(end) == 0){
						found = true;
						vector<string> track;
						genTrack(tree, pos, track);
						track.push_back(end);
						result.push_back(track);
						continue;
					}
					if(dict.count(cur) == 1 && (used.count(cur) == 0 || used[cur] >= pre )){
						used[cur] = pos;
						tree.push_back(make_pair(cur, pos));
					}
				}
			}
			pos++;
			if(!found && pos == last){
			    pre = last;
				last = tree.size();
			}
		}
		return result;
	}

};

int main(int argc, char **argv)
{
	Solution sl;
	unordered_set < string > dict;
	string data[] =
	    {"ted","tex","red","tax","tad","den","rex","pee"};
	for (int i = 0; i < 8; i++)
		dict.insert(data[i]);
	vector < vector < string > >ret = sl.findLadders( "red","tax", dict);

	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++)
			cout << ret[i][j] << " ";
		cout << endl;
	}

	return 0;

}
