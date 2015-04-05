#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;


class Solution {

private:
	int compute(vector<int>& weight){
		int i = 0, sum = 0, step = 0;
		int start;
		bool retry = false;
		for(int j = 0; j < weight.size(); ){
			i = j;
			sum = 0;
			start = i;
			step = 0;
			while(1){
				sum = sum + weight[i];
				if(i == weight.size() - 1){
					retry = true;
					i = 0;
				}
				else{
					i++;
				}
				if(sum < 0){
					break;
				}
				step++;
				if(step == weight.size())
					break;
			}
			if(step == weight.size())
				break;
			if(retry) return -1;
			j = i;
		}
		return start;
	}

public:

	int canCompleteCircuit_1st(vector<int> &gas, vector<int> &cost) {
		vector<int> weight;
		vector<int>::iterator iter_gas, iter_cost;
		int p = 0;
		for(iter_gas = gas.begin(), iter_cost = cost.begin(); 
			iter_gas != gas.end(); iter_gas++, iter_cost++){
			weight.push_back((*iter_gas) - (*iter_cost));
		}
		int start =  compute(weight);
		if(start != -1) return start;

		weight.clear();
		for(int i = 0, j = cost.size() -1; i < gas.size(); i++){
			weight.push_back(gas[i] - cost[j]);
			j = i;
		}
		start =  compute(weight);
		if(start != -1) return start;
		return -1;
    }

	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int size = gas.size();
		if(size == 0 || gas.size() != cost.size())
			return -1;
		if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
			return -1;
		int sum = 0;
		int start = -1;
		for(int i = 0; i < size; i++){
			sum += gas[i] - cost[i];
			if(sum >= 0 && start == -1)
				start = i;
			if(sum < 0){
				sum = 0;
				start = -1;
			}
		}
		return start;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> gas, cost;
	int data_gas[10] = {10,1,3,4,5,6,7,8,9,10};
	int data_cost[10] = {7,7,7,7,7,7,7,7,7,2};
	for(int i = 0; i < 10; i++){
		gas.push_back(data_gas[i]);
		cost.push_back(data_cost[i]);
	}
   cout<<sl.canCompleteCircuit(gas, cost)<<endl;;
	

	return 0;

}
