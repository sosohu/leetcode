#include <iostream>
#include <unordered_set>

using namespace std;


class Solution {

public:

	int change(int n){
		return n == 0? 0 : (n % 10) * (n % 10) + change(n/10);
	}

	bool isHappy(int n) {
		unordered_set<int> table;
		while(n != 1){
			table.insert(n);
			n = change(n);
			if(table.count(n))
				return false;
		}
		return true;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.isHappy(17)<<endl;

	return 0;

}
