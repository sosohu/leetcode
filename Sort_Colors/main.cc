#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	void sortColors_1st(int A[], int n) {
		int pos_1 = -1, pos_2 = -1;	
		for(int i = 0; i < n; i++){
			if(A[i] == 0){
				if(i == pos_1 + 1){
					pos_1++;
					pos_2++;
				}
				else{
					if(i == pos_2 + 1){
						pos_1++;
						pos_2++;
						A[pos_1] = 0;
						A[i] = 1;
					}else{
						pos_1++;
						pos_2++;
						A[i] = A[pos_2];
						A[pos_1] = 0;
						if(pos_2 !=  pos_1){
							A[pos_2] = 1;
						}
					}	
				}
				continue;
			}
			if(A[i] == 1){
				if(i == pos_2 + 1){
					pos_2++;
				}else{
					pos_2++;
					A[pos_2] = 1;
					A[i] = 2;
				}
			}
		}
    }

	void sortColors(int A[], int n) {
		if(n <= 1)	return;
		int zero_pos = 0, two_pos = n - 1;
		for(int i = 0; i <= two_pos;){
			if(A[i] == 0){
				if(zero_pos != i) swap(A[zero_pos], A[i]);
				else	i++;
				zero_pos++;
			}else if(A[i] == 2){
				if(two_pos != i) swap(A[two_pos], A[i]);
				else i++;
				two_pos--;
			}else{
				i++;
			}
		}
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {2, 0,1,1,2,1};
	int n = sizeof(A) / sizeof(int);
	sl.sortColors(A, n);
	
	for(int i = 0; i < n; i++)
		cout<<A[i]<<endl;

	return 0;

}
