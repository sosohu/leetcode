#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

	int countPrimes(int n) {
		if(n < 3)	return 0;
		vector<bool> table(n+1, true);
		int pos = 2, count = 0;
		while(pos < n){
			while(pos < n && !table[pos])	pos++;
			if(pos < n) count++;
			for(int i = 2; i * pos < n; i++)
				table[i*pos] = false;
			pos++;
		}
		return count;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.countPrimes(5)<<endl;

	return 0;

}
