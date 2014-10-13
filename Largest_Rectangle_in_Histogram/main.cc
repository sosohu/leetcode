#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	int largestRectangleArea(vector<int> &height) {
		int len = height.size();
		if(len == 0)	return 0;

		vector<int> left(len, 0), right(len, 0);

		for(int i = 1; i < len; i++){
			for(int j = i - 1; j >=0; j--){
				if(height[i] <= height[j]){
					left[i] = left[i] + left[j] + 1;
					j = j - left[j];
				}else{
					break;
				}
			}
		}
		for(int i = len - 2; i >= 0; i--){
			for(int j = i+1; j < len; j++){
				if(height[i] <= height[j]){
					right[i] = right[i] + right[j] + 1;
					j = j + right[j];
				}else{
					break;
				}
			}
		}
		int data = 0, tmp;

		for(int i = 0; i < len; i++){
			tmp = height[i] * (left[i] + right[i] + 1);
			if(data < tmp){
				data = tmp;
			}
		}
		return data;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> height(6, 0);
	height[0] = 2;
	height[1] = 1;
	height[2] = 5;
	height[3] = 6;
	height[4] = 2;
	height[5] = 3;

	int ret = sl.largestRectangleArea(height);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
