#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


class Solution {

public:

int maxProfit_1st(vector<int> &prices) {
		int sum = 0;
		int size = prices.size();
		if(size == 0) return 0;
		int valley = prices[0], peak = 0;
		for(int i = 0; i < size;){
			while(i+1 < size && prices[i] >= prices[i+1]){
				i++;
			}
			if(i+1 == size)
				break;
			if(valley > prices[i]){
				valley = prices[i];
				peak = 0;
			}
			while(i+1 < size && prices[i] <= prices[i+1]){
				i++;
			}
			if(prices[i] > peak)
				peak = prices[i];
			if(sum < peak - valley)
				sum = peak - valley;
			if(i+1 == size){
				break;
			}
		}
		return sum;
    }

int maxProfit(vector<int> &prices) {
	if(prices.size() == 0)	return 0;
	int rightMax = prices[prices.size() - 1];
	int get = 0;
	for(int i = prices.size() - 2; i >= 0; i--){
		rightMax = max(prices[i], rightMax);
		if(get < rightMax - prices[i])
			get = rightMax - prices[i];
	}
	return get;
}

};

int main(int argc, char** argv)
{
	Solution sl;
	int data[10] = {2,4,5,7,2,4,3,9,1,3};
	vector<int> prices;
	for(int i = 0; i < 10; i++)
		prices.push_back(data[i]);

    int ret = sl.maxProfit(prices);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
