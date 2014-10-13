#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {

public:

	inline vector<int> getNum(string &str, int len){
		vector<int> data(len, 0);

		for(int i = 0; i < len; i++){
			data[i] = (str[i] - '0');
		}
		return data;
	}

	inline void addOne(string &str, int num){
		switch(num){
			case 0: str = str + "0"; break;
			case 1: str = str + "1"; break;
			case 2: str = str + "2"; break;
			case 3: str = str + "3"; break;
			case 4: str = str + "4"; break;
			case 5: str = str + "5"; break;
			case 6: str = str + "6"; break;
			case 7: str = str + "7"; break;
			case 8: str = str + "8"; break;
			case 9: str = str + "9"; break;
			default:;
		}
	}

	inline string setNum(vector<int> num){
		string str;
		
		for(int i = 0; i < num.size(); i++)
			addOne(str, num[i]);

		return str;
	}	

	inline void mulOne(vector<vector<int> >& mul, vector<int> &num){
		int offset = mul[0].size() - num.size();
		int cin = 0;
		int tmp;
		for(int i = 0; i < 10; i++){
			cin = 0;
			for(int j = num.size() - 1; j >= 0; j--){
				tmp = num[j] * i + cin;
				cin = tmp/10;
				mul[i][j + offset] = tmp%10;
			}	
			mul[i][offset-1] = cin;
		}
	}

	inline void addOne(vector<int> &sum, vector<int> &num){
		int cin = 0;
		for(int i = sum.size() - 1; i >= 0; i--){
			sum[i] = sum[i] + num[i] + cin;
			cin = sum[i]/10;
			sum[i] = sum[i]%10;
		}
	}

	inline void leftshift(vector<int> &data, int count){
		if(count == 0)	return;
		vector<int>::iterator iter = data.begin();
		for(int i = 0; i < count; i++)
			iter++;
		vector<int> ret;
		ret.assign(iter, data.end());
		for(int i = 0; i < count; i++)
			ret.push_back(0);
		data.swap(ret);
	}

	void getMul(vector<int>& mul, vector<int> &num1, vector<int> &num2){
		int len1 = num1.size();
		int len2 = num2.size();
		vector<int> sum(len1+len2, 0);
		vector<vector<int> > back(10, vector<int>(len1+len2, 0));
		
		mulOne(back, num1);

		for(int i = len2 - 1; i >= 0; i--){
			vector<int> tmp(len1+len2, 0);
			tmp = back[num2[i]];
			leftshift(tmp, len2 - 1 - i);
			addOne(sum,  tmp);	
		} 			
		
		vector<int>::iterator iter = sum.begin();
		while(iter != sum.end() && *iter == 0){
			iter++;
		}
		if(iter != sum.end())
			mul.assign(iter, sum.end());
		else
			mul.push_back(0);
	}

	string multiply(string num1, string num2) {
		int len1 = num1.length();
		int len2 = num2.length();
		if(len1 * len2 == 0)
			return string("");
		vector<int> n1 = getNum(num1, len1);
		vector<int> n2 = getNum(num2, len2);

		vector<int> mul;


		getMul(mul, n1 , n2);
		
		return setNum(mul);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	//string num1("123456789"), num2("987654321");		
	string num1("0"), num2("0");		
	string ret = sl.multiply(num1, num2);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
