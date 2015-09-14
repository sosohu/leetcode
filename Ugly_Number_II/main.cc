#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:
	int nthUglyNumber(int n) {
		int mul[3] = {1, 1, 1};
        vector<long long> pos{1, 1, 1};
		vector<long long> ugly(n+1, 1);
		int index = 1;
		while(++index <= n){
			mul[0] = ugly[pos[0]] * 2;
			mul[1] = ugly[pos[1]] * 3;
			mul[2] = ugly[pos[2]] * 5;
			auto iter = min_element(begin(mul), end(mul));
			ugly[index] = *iter;
			for(int i = 0; i < 3; i ++)
				if(mul[i] == *iter)	pos[i]++;
		}
		return ugly[n];
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.nthUglyNumber(10)<<endl;

	return 0;

}
