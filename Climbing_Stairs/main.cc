#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int recursion(int n){
		if(n <= 2)
			return n;
		return recursion(n-1) + recursion(n-2);
	}

	int climbStairs(int n) {
		//return recursion(n);
		if(n <= 2)
			return n;
		int a1 = 1, a2 = 2;

		for(int i = 3; i <= n; i++){
			a2 = a1 + a2;
			a1 = a2 - a1;
		}
		return a2;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
    int ret = sl.climbStairs(44);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
