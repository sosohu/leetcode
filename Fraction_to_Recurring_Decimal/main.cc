#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;


class Solution {

public:

	string num2str(int num){
		if(num == 0)	return "0";
		if(num < 0)	return "-" + num2str(-num);
		string result = "";
		while(num){
			result.push_back((num % 10) + '0');
			num /= 10;
		}
		reverse(result.begin(), result.end());
		return result;
	}

	struct hashPair{
		size_t operator()(const pair<int, int> key) const{
			return key.first ^ key.second;
		}
	};

	string fractionToDecimal(int numerator, int denominator) {
		string result;
		if(denominator == 0)	return result;
		if(numerator == 0)	return "0";
		bool isMunis = true;
		if((numerator < 0 && denominator < 0) || (numerator > 0 && denominator > 0)){
			isMunis = false;
		}
		numerator = numerator < 0? numerator : -numerator;
		denominator = denominator < 0? denominator : -denominator;
		if(numerator == INT_MIN && denominator == -1){
		    result = "2147483648";
		    numerator = 0;
		}
		else{
		    int ret = 0;
		    while(numerator <= denominator){
		    	ret = ret + numerator / denominator;
			    numerator = numerator - denominator * (numerator / denominator);
		    }
		    result = num2str(ret);
		}
		if(numerator){
			result.push_back('.');
			int pos = result.size() - 1;
			unordered_map<pair<int, int>, int, hashPair> table;
			double numerator_d = numerator, denominator_d = denominator;
			while(int(numerator_d)){
				if(table.count(make_pair(int(numerator_d), int(denominator_d)))){
					int index = table[make_pair(int(numerator_d), int(denominator_d))];
					result.insert(index, 1, '(');
					result.push_back(')');
					break;
				}
				pos++;
				table[make_pair(int(numerator_d), int(denominator_d))] = pos;
				numerator_d *= 10;
				int cur = numerator_d / denominator_d;
				numerator_d = numerator_d - denominator_d * cur;
				result.push_back('0' + cur);
			}
		}
		return isMunis? "-" + result : result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.fractionToDecimal(22,7)<<endl;

	return 0;

}
