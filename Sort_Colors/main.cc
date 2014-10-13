#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	void sortColors(int A[], int n) {
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

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {2, 0};
	sl.sortColors(A, 2);
	
	for(int i = 0; i < 2; i++)
		cout<<A[i]<<endl;

	return 0;

}
