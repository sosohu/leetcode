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

	int climbStairs_1st(int n) {
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

	int climbStairs(int n) {
		if(n <= 1)	return n;
		int fn1 = 2, fn2 = 1, fn = 2;
		for(int i = 3; i <= n; i++){
			fn = fn1 + fn2;
			fn2 = fn1;
			fn1 = fn;
		}
		return fn;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
    int ret = sl.climbStairs(44);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
