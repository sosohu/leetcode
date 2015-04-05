#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

	int maxProfit_1st(vector<int> &prices) {
		int sum = 0;
		int valley = 0;
		int size = prices.size();
		for(int i = 0; i < size;){
			while(i+1 < size && prices[i] >= prices[i+1]){
				i++;
			}
			if(i+1 == size)
				break;
			valley = prices[i];
			while(i+1 < size && prices[i] <= prices[i+1]){
				i++;
			}
			if(prices[i] - valley > 0)
				sum = sum + prices[i] - valley;
			if(i+1 == size){
				break;
			}
		}
		return sum;
    }

	int maxProfit(vector<int> &prices) {
		int last = -1;
		int sum = 0;
		int size = prices.size();
		for(int i = 0; i < size - 1; i++){
			if(prices[i] < prices[i+1] && last == -1)
				last = prices[i];
			if(prices[i] > prices[i+1] && last != -1){
				sum +=  prices[i] - last;
				last = -1;
			}
		}
		if(last != -1){
			sum += prices[size - 1] - last;
		}
		return sum;
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
