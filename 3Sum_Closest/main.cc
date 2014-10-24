#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;


class Solution {

	class mysort{
		public:
			bool operator()(pair<int, pair<int, int> > i, 
							pair<int, pair<int, int> > j){
				return i.first < j.first;
			}
	} mysort;

public:

	int binarysearch(vector<pair<int, pair<int, int> > > &table, int start, int end,  int target){
		if(start == end){
			return table[start].first;
		}
		if(start == end - 1){
			int t_s = table[start].first - target;
			int t_e = table[end].first - target;
			return abs(t_s) < abs(t_e)? t_s + target : t_e + target;
		}

		int mid = (start + end) / 2;
		if(table[mid].first == target){
			return target;
		}
		if(table[mid].first < target){
			return binarysearch(table, mid+1, end, target);
		}else{
			return binarysearch(table, start, mid-1, target);
		}
	}

	int recusion(vector<int> &num, vector<pair<int, pair<int, int> > > &table,
					int size, int table_size, int target, int pos){
		int cur;
		if(pos == size - 3){
			return num[pos] + num[pos+1] + num[pos+2];
		}
		// remove the item contain the num[pos]
		int last = 0;
		for(int i = 0; i < table_size; i++){
			if(table[i].second.first != pos){
				if(last != i){
					table[last] = table[i];
					last++;
				}
			}
		}
		int left = target - num[pos];
		cur = binarysearch(table, 0, last, left);
		cur = cur + num[pos];
		int other = recusion(num, table, size, last+1, target, pos+1);
		cout<<cur<<" "<<other<<endl;
		return abs(cur-target) < abs(other-target)? cur : other;
	}

	int threeSumClosest(vector<int> &num, int target) {
		int size = num.size();
		if(size < 3)	return 0;
		vector<pair<int, pair<int, int> > > table;
		for(int i = 0; i < size; i++){
			for(int j = i + 1; j < size; j++){
				table.push_back(pair<int, pair<int, int> >
								(num[i]+num[j], pair<int, int>(i, j)));
			}
		}
		sort(table.begin(), table.end(), mysort);
		return recusion(num, table, size, table.size(), target, 0);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {2,39,66,69,-5,54,-51,47,-20,82,41,-96,38,-87,-18,21,59,70,100,37,-25,8,-38,-27,75,24,69,-43,92,-55,87,-96,-34,-2,70,3,29,2,-32,58,3,56,33,-11,61,0,-40,25,-27,-73,-67,-23,-53,-62,20,-25,33,-27,-45,57,3,86,-18,-84,-4,-74,-99,67,-54,-70,-14,29,-41,-80,28,24,59,75,-52,-21,-48,27,-24,-30,-88,51,60,-15,2,86,63,-28,-51,-97,-60,92,-79,-20,-44,12,83,100,9,-76,-7,-75,36,23,3,-55,-3,-37,-64,16,40,6,-24,-30,-53,-78,-32,63,-53,54,38,19,55,-90,80,-93,-68,-7,71,-92,-9,15,53,-76,-30,27,72,76,36,-77,-4,68,34,29,-45,-60,-55,29,53,-45,0,84,52,30,57,1,9,-99,77,14,14,-75,15,-9,8,-84,-94,47,59,-31,-83,9,68,-1,-68,64,55,18,42};
	vector<int> data(183,0);
	for(int i = 0; i < data.size(); i++)
		data[i] = A[i];
	
	int ret = sl.threeSumClosest(data, -230);

	cout<<ret<<endl;

	return 0;

}
