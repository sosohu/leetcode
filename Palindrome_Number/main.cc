#include <iostream>
#include <climits>

using namespace std;


class Solution {

public:

	bool isPalindrome_1st(int x) {
		if(x < 0){
			return false;
		}
		int com = 1000000000;
		int last, first, left;
		left = x;
		while(com > 0){
			if(x >= com){
				last = left % 10;
				first = left / com;
				if(last != first) return false;
				left = left - first * com;
				left = left / 10;
				com = com / 100;
			}else{
				com = com / 10;
			}
		}
		return true;
    }

	bool isPalindrome(int x) {
		if(x < 0 || (x != 0 && x % 10  == 0)) return false;
		int rev = 0;
		while(x > rev){
			rev = rev * 10 + (x % 10);
			x = x / 10;
		}
		return (x == rev) || (x == rev/10);
	}

};

int main(int argc, char** argv)
{
	Solution sl;
    int ret = sl.isPalindrome(4);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
