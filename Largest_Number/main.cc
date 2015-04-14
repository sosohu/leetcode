#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


class Solution {

public:

	static int march_bucket(int val, int pos){
		return (val / ((int)pow(10,pos))) % 10;
	}
	
	class mysort{
	public:
		bool cmp(vector<int> &a, vector<int> &b){
			int i = a.size() - 1;
			for(; i >= 0 && a[i] == b[i]; i--)
				;
			return i < 0? true : a[i] > b[i];
		}
		
		// return true if x > y
		bool operator()(int x, int y){
			if(x == 0 || y == 0)	return x > y;
			int i = 9, j = 9;
			vector<int> a(10,0), b(10,0);
			while(i >= 0){
				a[i] = Solution::march_bucket(x, i);
				b[i] = Solution::march_bucket(y, i);
				i--;
			}
			i = 9;
			while(i >= 0 && a[i] == 0)
				i--;
			while(j >= 0 && b[j] == 0)
				j--;
			vector<int> ab, ba;
			ab.insert(ab.end(), b.begin(), b.begin() + j +1);
			ab.insert(ab.end(), a.begin(), a.begin() + i + 1);
			ba.insert(ba.end(), a.begin(), a.begin() + i + 1);
			ba.insert(ba.end(), b.begin(), b.begin() + j +1);
			return cmp(ab , ba);
		}
	};

	string genString(int ele){
		string ret;
		int i = 9;
		bool start = false;
		while(i >= 0){
			int cur = march_bucket(ele, i);
			if(cur != 0 && !start)	start = true;
			if(start)	ret.push_back(cur + '0');
			i--;
		}
		if(!start)	return "0";
		return ret;
	}

	string largestNumber(vector<int> &num) {
		sort(num.begin(), num.end(), mysort());
		string result;
		for(auto ele : num){
			if(ele == 0 && result.empty())
				return "0";
			else
				result = result + genString(ele);
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> num{12, 121, 0};

	string ret = sl.largestNumber(num);
	cout<<ret<<endl;
	return 0;

}
