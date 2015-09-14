#include <iostream>
#include <string>
#include <vector>

using namespace std;

string single[20] = {"One", "Two", "Three", "Four", "Five",
					 "Six", "Seven", "Eight", "Nine", "Ten",
					 "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
					 "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};

string ten[10] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty",
				  "Sixty", "Seventy", "Eighty", "Ninety", "Hundred"};

string base[4] = {"", "Thousand", "Million", "Billion"};
int level[4] = {1, 1000, 1000000, 1000000000};

class Solution {

public:

	/*
		num: [0, 1000)
	*/
	void numberToWords_aux(int num, vector<string> &res, string padding = ""){
		if(num == 0)	return;
		if(num >= 100){
			int index = num / 100;
			res.push_back(single[index - 1]);
			res.push_back("Hundred");
			num = num - index * 100;
		}
		if(num >= 20){
			int index = num / 10;
			res.push_back(ten[index - 1]);
			num = num - index * 10;
		}
		if(num > 0)
			res.push_back(single[num - 1]);
		if(padding.size())
			res.push_back(padding);
	}

	string numberToWords(int num) {
		if(num == 0)	return "Zero";
		string res;
		vector<string> part;
		for(int i = 3; i >= 0; i--){
			if(num >= level[i]){
				int high = num / level[i];
				numberToWords_aux(high, part, base[i]);
				num = num - high * level[i];
			}
		}
		res = part[0];
		for(int i = 1; i < part.size(); i++){
			res = res + " " + part[i];
		}
		return res;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.numberToWords(121230223)<<endl;


	return 0;

}
