#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;


class Solution {

public:

	int ladderLength_1st(string start, string end, unordered_set<string> &dict) {
		int len = start.length();
		unordered_set<string> find;
		queue<string> data;

		data.push(start);
		find.insert(start);
		string str, tmp;
		int length = 0;
		int size;
		while(!data.empty()){
			size = data.size();
			length++;
			for(int i = 0; i < size; i++){
				str = data.front();
				data.pop();
				if(str.compare(end) == 0) 
					return length;
				for(int j = 0; j < len; j++){
				 	tmp = str;
					for(int k = 97; k < 123; k++){
						tmp[j] = k;
						if(dict.count(tmp) == 1 && find.count(tmp) == 0){
							data.push(tmp);
							find.insert(tmp);
						}
					}
				}
			}
		}
		return 0;
    }

	int ladderLength(string start, string end, unordered_set<string> &dict) {
		unordered_set<string> used;
		queue<string> q;
		q.push(start);
		dict.insert(start);
		dict.insert(end);
		used.insert(start);
		int deep = 0, last = 1;
		while(!q.empty()){
			start = q.front();
			q.pop();
			if(start.compare(end) == 0)	return deep + 1;
			string tmp = start;
			for(int i = 0; i < start.size(); i++){
				start = tmp;
				for(int j = 'a'; j <= 'z'; j++){
					start[i] = j;
					if(dict.count(start) && !used.count(start)){
						used.insert(start);
						q.push(start);
					}
				}
			}
			last--;
			if(last == 0){
				last = q.size();
				deep++;
			}
		}
		return 0;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	unordered_set<string> dict;
	string data[] = {"miss","dusk","kiss","musk","tusk","diss","disk","sang","ties","muss"};
	for(int i = 0; i < 10; i++)
		dict.insert(data[i]);
    int ret = sl.ladderLength("kiss", "tusk", dict);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
