#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	vector<int> plusOne(vector<int> &digits) {
		int len = digits.size();
		if(len == 0){
			return digits;
		}
		int i;
		for(i = len -1; i >= 0; i--){
			if(digits[i] + 1 == 10){
				digits[i] = 0;
			}
			else
				break;
		}
		if(i < 0){
			vector<int> data(len+1, 0);
			data[0] = 1;
			return data;
		}
		digits[i] = digits[i] + 1;
		return digits;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> digits(3, 0);
	digits[0] = 9;
	digits[1] = 9;
	digits[2] = 9;

	vector<int> data = sl.plusOne(digits);
	
	for(int i = 0; i < data.size(); i++)
		cout<<data[i];
	cout<<endl;

	return 0;

}
