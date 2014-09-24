#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
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

	void MTrace(string start, string str, vector<vector<string> >& path,
		   unordered_map<string, vector<string> >& father) {
		vector<vector<string> > vec_vec;
		vec_vec = Trace(start, str, father);
		for(int i = 0; i < vec_vec.size(); i++)
			path.push_back(vec_vec[i]);
	}

	 vector < vector < string > >findLadders(string start, string end,
						  unordered_set < string >
						  &dict) {
		int len = start.length();
		unordered_set < string > find;
		vector < vector < string > > path;
		unordered_map < string, vector < string > >father;
		queue < string > data;

		find.insert(start);
		data.push(start);
		string str, tmp;
		while (!data.empty()) {

			int size = data.size();
			unordered_set < string > cur;
			for (int k = 0; k < size; k++) {

				str = data.front();
				data.pop();

				if (str.compare(end) == 0) {
					MTrace(start, str, path, father);
					return path;
				}
				for (int i = 0; i < len; i++) {
					tmp = str;
					for (int j = 97; j < 123; j++) {
						tmp[i] = j;
						if (dict.count(tmp) == 1 && find.count(tmp) == 0) {
							data.push(tmp);
							cur.insert(tmp);
							father[tmp].push_back(str);
						}
					}
				}
			}
			find.insert(cur.begin(), cur.end());
		}

		return path;
	}

};

int main(int argc, char **argv)
{
	Solution sl;
	unordered_set < string > dict;
	string data[] =
	    { "miss", "dusk", "kiss", "musk", "tusk", "diss", "disk", "sang",
	"ties", "muss" };
	for (int i = 0; i < 10; i++)
		dict.insert(data[i]);
	vector < vector < string > >ret = sl.findLadders("kiss", "tusk", dict);

	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++)
			cout << ret[i][j] << " ";
		cout << endl;
	}

	return 0;

}
