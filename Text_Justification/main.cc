#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	vector<string> fullJustify(vector<string> &words, int L) {
		int size = words.size();
		vector<string> data;

		int left = L, word_size, used, word_count, add, remain;
		vector<string> line;
		for(int i = 0; i < size; i++){
			word_size = words[i].size();
			if(left >= word_size){
				line.push_back(words[i]);
				used = used + word_size + 1;
				left = left - word_size - 1;
			}else{
				left++;
				word_count = line.size();
				if(word_count == 1){
					string line_str = line[0];
					string add_str(L - line_str.length(), ' ');
					line_str = line_str + add_str;
					data.push_back(line_str);
				}
				else{
					add = left / (word_count - 1);
					remain = left - (word_count - 1)* add;
					add = add + 1;
					string space1(add + 1, ' '), space2(add, ' ');
					string line_str;
					for(int j = 0; j < remain; j++){
						line_str = line_str + line[j] + space1;
					}
					for(int j = remain; j < word_count - 1; j++){
						line_str = line_str + line[j] + space2;
					}
					line_str = line_str + line[word_count - 1];
					data.push_back(line_str);
				}
				left = L;
				i--;
				line.clear();
			}
		}
		string line_str;
		for(int j = 0; j < line.size() - 1; j++){
			line_str = line_str + line[j] + " ";
		}
		line_str = line_str + line[line.size() - 1];
		string add_str(L - line_str.length(), ' ');
		line_str = line_str + add_str;
		
		data.push_back(line_str);
		return data;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<string> words(7, "");
	words[0] = "This";
	words[1] = "is";
	words[2] = "an";
	words[3] = "example";
	words[4] = "of";
	words[5] = "text";
	words[6] = "justification";

	vector<string> ret = sl.fullJustify(words, 16);
	
	for(int i = 0; i < ret.size(); i++)
		cout<<ret[i]<<endl;

	return 0;

}
