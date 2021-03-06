#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <unordered_map>

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

	vector<vector<int> > threeSum_1st(vector<int> &num) {
		int size = num.size();
		vector<vector<int> > data;
		if(size < 3)	return data;
		unordered_map<int, vector<int> > table;
		
		sort(num.begin(), num.end(), mysort);
		for(int i = 0; i < size; i++){
			table[num[i]].push_back(i);
		}
		
		int last;
		for(int i = 0; i < size - 2; i++){
			if(i > 0 && num[i] == num[i-1])	continue;
			for(int j = i + 1; j < size - 1; j++){
				if(j > i + 1 && num[j] == num[j-1])	continue;
				int left = 0 - num[i] - num[j];
				if(table.count(left) == 1){
					last = table[left][table[left].size() - 1];
					if(last > j){
						data.push_back(vector<int>{num[i], num[j], num[last]});
					}
				}
			}
		}
		return data;
    }

	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > result;
		if(num.size() < 3)	return result;
		unordered_map<int, int> table;
		sort(num.begin(), num.end());
		vector<pair<int, int> >  shrink;
		int last = num[0], pos = 0;
		table[num[0]] = 1;
		shrink.push_back(make_pair(num[0], 1));
		for(int i = 1; i < num.size(); i++){
			if(last == num[i]){
				shrink[pos].second++;
				table[last]++;
			}else{
				shrink.push_back(make_pair(num[i], 1));
				last = num[i];
				table[last] = 1;
				pos++;
			}				
		}
		for(int i = 0; i < shrink.size(); i++)
			for(int j = i; j < shrink.size(); j++){
				if(j == i && shrink[i].second == 1) continue;
				int left = 0 - shrink[i].first - shrink[j].first;
				if(table.count(left) == 0)	continue;
				if(left < shrink[j].first)	break;
				if(left == shrink[j].first && j == i
					 && shrink[j].second == 2)	break;
				if(left == shrink[j].first && shrink[j].second == 1)	break;
				result.push_back(vector<int>{shrink[i].first, shrink[j].first, left});
			}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	//int A[] = {2,39,66,69,-5,54,-51,47,-20,82,41,-96,38,-87,-18,21,59,70,100,37,-25,8,-38,-27,75,24,69,-43,92,-55,87,-96,-34,-2,70,3,29,2,-32,58,3,56,33,-11,61,0,-40,25,-27,-73,-67,-23,-53,-62,20,-25,33,-27,-45,57,3,86,-18,-84,-4,-74,-99,67,-54,-70,-14,29,-41,-80,28,24,59,75,-52,-21,-48,27,-24,-30,-88,51,60,-15,2,86,63,-28,-51,-97,-60,92,-79,-20,-44,12,83,100,9,-76,-7,-75,36,23,3,-55,-3,-37,-64,16,40,6,-24,-30,-53,-78,-32,63,-53,54,38,19,55,-90,80,-93,-68,-7,71,-92,-9,15,53,-76,-30,27,72,76,36,-77,-4,68,34,29,-45,-60,-55,29,53,-45,0,84,52,30,57,1,9,-99,77,14,14,-75,15,-9,8,-84,-94,47,59,-31,-83,9,68,-1,-68,64,55,18,42};
	//vector<int> data(183,0);
	int A[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector<int> data(109,0);
	for(int i = 0; i < data.size(); i++)
		data[i] = A[i];
	
	vector<vector<int> > ret = sl.threeSum(data);

	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++){
			cout<<ret[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;

}
