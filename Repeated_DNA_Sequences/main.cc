/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-05-09 18:10
 * Filename :        main.cc
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {

public:

	int genNum(char c){
		switch (c){
			case 'A': return 0;
			case 'C': return 1;
			case 'G': return 2;
			case 'T': return 3;
			default:  return -1;
		}
	}

	int genId(string &str, int start){
		int sum = 0;
		for(int i = start; i < start + 10; i++)
			sum = sum*4 + genNum(str[i]);
		return sum;
	}

    vector<string> findRepeatedDnaSequences_1st(string s) {
		vector<string> result;
		unordered_map<int, pair<int,int> > table;
		for(int i = 0; i < (int)(s.size()) - 9; i++){
			int id = genId(s, i);
			if(!table.count(id))
				table[id] = make_pair(1, i);
			else
				table[id].first++;
		}
		for(auto iter = table.begin(); iter != table.end(); iter++)
			if(iter->second.first > 1)
				result.push_back(s.substr(iter->second.second, 10));
		return result;
    }

    vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		unordered_map<int, int> table;
		for(int i = 0; i + 9 < s.size(); i++){
			unsigned int code = 0x0;
			for(int j = 0; j < 10; j++)
				code |= (((s[i+j] & 0x6) >> 1) << (2*j));
			if(table[code] == 1) result.push_back(s.substr(i,10));
			table[code]++;
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<string> ret = sl.findRepeatedDnaSequences("AAAAAAAAAAAA");
	for(auto ele : ret)
		cout<<ele<<endl;

	return 0;

}
