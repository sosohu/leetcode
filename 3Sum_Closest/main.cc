#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;


class Solution {

	class mysort{
		public:
			bool operator()(int i, 
							int j){
				return i < j;
			}
	} mysort;

public:

	int threeSumClosest(vector<int> &num, int target) {
		int size = num.size();
		if(size < 3)	return 0;
		sort(num.begin(), num.end(), mysort);
		int pos = 0;
		int cur, left, low, high;
		int last_one;
		int last = -(((-1)<<31)+1);
		while(pos < size - 2){
			left = target - num[pos];
			low = pos + 1;
			high = size - 1;
			while(low < high){
				cur = num[low] + num[high];
				if(last > abs(cur - left)){
					last = abs(cur - left);
					last_one = cur + num[pos];
				}
				if(cur < left){
					low++;
				}else{
					high--;
				}
			}
			pos++;
		}
		return last_one;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	//int A[] = {2,39,66,69,-5,54,-51,47,-20,82,41,-96,38,-87,-18,21,59,70,100,37,-25,8,-38,-27,75,24,69,-43,92,-55,87,-96,-34,-2,70,3,29,2,-32,58,3,56,33,-11,61,0,-40,25,-27,-73,-67,-23,-53,-62,20,-25,33,-27,-45,57,3,86,-18,-84,-4,-74,-99,67,-54,-70,-14,29,-41,-80,28,24,59,75,-52,-21,-48,27,-24,-30,-88,51,60,-15,2,86,63,-28,-51,-97,-60,92,-79,-20,-44,12,83,100,9,-76,-7,-75,36,23,3,-55,-3,-37,-64,16,40,6,-24,-30,-53,-78,-32,63,-53,54,38,19,55,-90,80,-93,-68,-7,71,-92,-9,15,53,-76,-30,27,72,76,36,-77,-4,68,34,29,-45,-60,-55,29,53,-45,0,84,52,30,57,1,9,-99,77,14,14,-75,15,-9,8,-84,-94,47,59,-31,-83,9,68,-1,-68,64,55,18,42};
	//vector<int> data(183,0);
	int A[] = {1,2,4,8,16,32,64,128};
	vector<int> data(8,0);
	for(int i = 0; i < data.size(); i++)
		data[i] = A[i];
	
	int ret = sl.threeSumClosest(data, 82);

	cout<<ret<<endl;

	return 0;

}
