#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>

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

	int threeSumClosest_1st(vector<int> &num, int target) {
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

	void binarySearch(vector<int> &num, int begin, int end,
						 int target, int sum, int &result){
		if(begin > end)	return;
		int mid = (begin + end) / 2;
		if(sum + num[mid] == target){
			result = target;
			return;
		}
		if(result == INT_MAX || abs(target - result) > abs(target - sum - num[mid]))
			result = sum + num[mid];
		if(sum + num[mid] > target)
			binarySearch(num, begin, mid-1, target, sum, result);
		else
			binarySearch(num, mid+1, end, target, sum, result);
	}

	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int result = INT_MAX;
		for(int i = 0; i < num.size() - 2; i++)
			for(int j = i + 1; j < num.size() - 1; j++){
				int sum = num[i] + num[j];
				binarySearch(num, j + 1, num.size() - 1, target, sum, result);
			}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	//int A[] = {2,39,66,69,-5,54,-51,47,-20,82,41,-96,38,-87,-18,21,59,70,100,37,-25,8,-38,-27,75,24,69,-43,92,-55,87,-96,-34,-2,70,3,29,2,-32,58,3,56,33,-11,61,0,-40,25,-27,-73,-67,-23,-53,-62,20,-25,33,-27,-45,57,3,86,-18,-84,-4,-74,-99,67,-54,-70,-14,29,-41,-80,28,24,59,75,-52,-21,-48,27,-24,-30,-88,51,60,-15,2,86,63,-28,-51,-97,-60,92,-79,-20,-44,12,83,100,9,-76,-7,-75,36,23,3,-55,-3,-37,-64,16,40,6,-24,-30,-53,-78,-32,63,-53,54,38,19,55,-90,80,-93,-68,-7,71,-92,-9,15,53,-76,-30,27,72,76,36,-77,-4,68,34,29,-45,-60,-55,29,53,-45,0,84,52,30,57,1,9,-99,77,14,14,-75,15,-9,8,-84,-94,47,59,-31,-83,9,68,-1,-68,64,55,18,42};
	//vector<int> data(183,0);
	int A[] = {1,1,1,0};
	//int A[] = {-11,-2,17,-16,1,-5,-5,-5,-20,7,10,-2,3,-7,-17,-13,-19,-15,-8,-7,6,-6,-8,-4,12,-12,9,-17,-13,4,-5,-15,-9,-18,-17,1,-15,-8,14,8,20,-3,-11,17,-18,10,-16,5,-9,-18,2,-3,4,-18,2,20,0,-6,18,-12,0,-17,3,-19,-20,15,12,-17,-7,8,16,7,-5,5,-13,16,-18,-7,-9,-8,-17,6,-18,0,-15,10,-13,7,9,20,7,-13,3,0,0,19,8,0,-5,-9,6,8,16,14,3,-4,5,9,-12,-19,16,6};
	vector<int> data(begin(A),end(A));
	for(int i = 0; i < data.size(); i++)
		data[i] = A[i];
	
	int ret = sl.threeSumClosest(data, 100);

	cout<<ret<<endl;

	return 0;

}
