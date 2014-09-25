#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

      public:

	vector<vector<string> > Trace(string start, string str,
		   unordered_map<string, vector<string> >& father) {
		vector<string> vec;
		vector<vector<string> > path;

		if(start.compare(str) == 0){
			vec.push_back(str);
			path.push_back(vec);
			return path;
		}

		string tmp;
		vector<vector<string> > vec_vec;
		for(int i = 0; i < father[str].size(); i++){
			tmp = father[str][i];
			vec_vec = Trace(start, tmp, father);
			for(int j = 0; j < vec_vec.size(); j++){
				vec_vec[j].push_back(str);
				path.push_back(vec_vec[j]);
			}
		}
		return path;
	}

	 vector < vector < string > >findLadders(string start, string end,
						  unordered_set < string >
						  &dict) {
		int len = start.length();
		unordered_set < string > find;
		vector < vector < string > > path;
		unordered_map < string, vector < string > >father;
		vector < string > data;

		bool this_level = false;
		find.insert(start);
		data.push_back(start);
		string str, tmp;
		int length = 0;
		while (!data.empty()) {

			length++;
			if(length > 25*len)
				break;
			int size = data.size();
			unordered_set < string > cur;
			vector<string> local_data;
			for (int k = 0; k < size; k++) {

				str = data[k];

				for (int i = 0; i < len; i++) {
					tmp = str;
					for (int j = 97; j < 123; j++) {
						tmp[i] = j;
						if (tmp.compare(end) == 0){
							this_level = true;
							father[tmp].push_back(str);
						}else{
							if (dict.count(tmp) == 1 && find.count(tmp) == 0) {
								local_data.push_back(tmp);
								father[tmp].push_back(str);
								if(cur.count(tmp) == 0)
									cur.insert(tmp);
							}
						}
					}
				}
			}
			if(this_level){
				path = Trace(start, end, father);
				return path;
			}
			find.insert(cur.begin(), cur.end());
			data = local_data;
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
