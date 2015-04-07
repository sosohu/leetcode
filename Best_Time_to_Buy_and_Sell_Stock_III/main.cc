#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;


class Solution {

public:

int maxProfit_1st(vector<int> &prices) {
		int len = prices.size();
		if(len <= 1)	return 0;

		int begin[len], begin_min[len];
		int end[len], end_max[len];
		int begin_tmp, end_tmp;
		
		begin[0] = 0; begin_min[0] = prices[0];
		end[0] = 0;  end_max[0] = prices[len-1];
		for(int i = 1; i < len; i++){
			begin_tmp = prices[i] - begin_min[i-1];
			begin[i] = begin_tmp > begin[i-1]? begin_tmp : begin[i-1];
			begin_min[i] = prices[i] < begin_min[i-1]? prices[i] : begin_min[i-1];
			
			end_tmp = end_max[i - 1] - prices[len - 1 - i];
			end[i] = end_tmp > end[i-1]? end_tmp : end[i-1];
			end_max[i] = prices[len - 1 - i] > end_max[i-1]? prices[len-1-i] : end_max[i-1];
		}
		#ifdef DEBUG
		for(int i = 0; i < len; i++){
			cout<<"begin "<<begin[i]<<"  end  "<<end[i]<<endl;
		}
		#endif

		if(len == 2)
			return begin[1];
		
		int max = 0;
		int tmp;
		for(int i = 1; i < len - 1; i++){
			tmp = begin[i] + end[len - 1 - i];
			if(max < tmp)
				max = tmp;
		}	

		return max;
    }

int maxProfit(vector<int> &prices) {
	int n = prices.size();
	vector<int> left(n+1, 0);
	//left[i]表示a[0],...a[i-1]单次购买最大利润
	vector<int> right(n+1, 0);
	//right[i]表示a[i],...a[n-1]单次购买最大利润
	int left_min = INT_MAX, right_max = INT_MIN;
	for(int i = 1; i <= n; i++){
		left_min = min(prices[i-1], left_min);
		left[i] = max(left[i-1], prices[i-1] - left_min);
	}
	for(int i = n-1; i >= 0; i--){
		right_max = max(prices[i], right_max);
		right[i] = max(right_max - prices[i], right[i+1]);
	}
	//以i为切割点，求左右两部分各自最大利润再综合
	int maxEarn = INT_MIN;
	for(int i = 0; i <= n; i++){
		maxEarn = max(maxEarn, left[i] + right[i]);
	}
	return maxEarn;
}


};

int main(int argc, char** argv)
{
	Solution sl;
	int data[4] = {1,7,2,4};
	vector<int> prices;
	for(int i = 0; i < 4; i++)
		prices.push_back(data[i]);

    int ret = sl.maxProfit(prices);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
