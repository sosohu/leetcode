#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	int recursion(int A[], int sa, int ea, int B[], int sb, int eb, int k1, int k2){
		int ma = (sa + ea) / 2;
		int mb = (sb + eb) / 2;
		if(ma < mb){
			int len = ma - sa + 1;
			if(len < k1){
				k1 = k1 - len;
				k2 = k2 - len;
				return recursion(A, ma+1, ea, B, );
			}
		}else{

		}	
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if(m == 0 && n == 0)	return 0;
		return recursion(A, 0, m-1, B, 0, n-1, (n+m)/2, (n+m+1)/2);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	string s("  hello my world ada ");		
    sl.reverseWords(s);
	
	cout<<"Result  :("<<s<<")"<<endl;

	return 0;

}
