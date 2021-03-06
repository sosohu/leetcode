#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {

public:

	vector<vector<int> > recursion(vector<int> &num, unordered_map<int, vector<pair<int, int> > > &table, int target, int pos, int size){
		vector<vector<int> > data;
		if(pos == size - 4){
			if(num[pos] + num[pos+1] + num[pos+2] + num[pos+3] == target){
				vector<int> vec(num.begin() + pos, num.end());
				data.push_back(vec);
			}
			return data;
		}
		int left = target - num[pos];
		int half;
		vector<int> vec(4,0);
		vec[0] = num[pos];
		int count = 0;
		for(int i = pos + 1; i < size; i++){
			if(i > pos + 1 && num[i] == num[i-1])	continue;
			half = left - num[i];
			if(table.count(half) == 1){
				vec[1] = num[i];
				for(int j = 0; j < table[half].size(); j++){
					if(table[half][j].first > i && table[half][j].second > i){
						vec[2] = num[table[half][j].first];
						vec[3] = num[table[half][j].second];
						if(!(count > 0 &&  data[count-1][0] == vec[0]
										&& data[count-1][1] == vec[1]
										&& data[count-1][2] == vec[2]
										&& data[count-1][3] == vec[3])){
							data.push_back(vec);
							count++;
						}
					}
				}
			}
		}
		while(pos < size - 1){
			if(num[pos] != num[pos+1])
				break;
			pos++;
		}
		if(pos < size - 1){
			vector<vector<int> > sub_data = recursion(num, table, target, pos+1, size);
			data.insert(data.end(), sub_data.begin(), sub_data.end());
		}
		return data;
	}

	vector<vector<int> > fourSum_1st(vector<int> &num, int target) {
		int size = num.size();
		if(size <= 3){
		    vector<vector<int> > data;
		    return data;
		}
		sort(num.begin(), num.end());
		unordered_map<int, vector<pair<int, int> > > table;
		for(int i = 0; i < size; i++){
			for(int j = i + 1; j < size; j++){
				table[num[i] + num[j]].push_back(pair<int, int>(i, j));
			}
		}
		#ifdef DEBUG
		for(unordered_map<int, vector<pair<int, int> > >::iterator iter = table.begin(); iter != table.end(); iter++){
			cout<<iter->first<<" ";
			for(int i = 0; i < iter->second.size(); i++){
				cout<<" (";
				cout<<(iter->second)[i].first<<","<<(iter->second)[i].second;
				cout<<") ";
			}
			cout<<endl;
		}
		#endif
		return recursion(num, table, target, 0, size);
    }

	vector<vector<int> > fourSum(vector<int> &num, int target) {
		int n = num.size();
		vector<vector<int> > result;
		unordered_map<int,vector<int> > table;
		sort(num.begin(), num.end());
		for(int i = 0; i < n - 1; i++){
			if(num[i] == num[i+1]){
				while(i < n - 1 && num[i] == num[i+1]) i++;
				i--;
				table[num[i] + num[i+1]].push_back(i);
				continue;
			}
			for(int j = i + 1; j < n; j++){
				if(j < n - 1 && num[j] == num[j+1]){
					 table[num[i] + num[j]].push_back(i);
					 while(j < n - 1 && num[j] == num[j+1]) j++;
					 continue;
				}
				table[num[i] + num[j]].push_back(i);
			}
		}
		for(int i = 0; i < n - 3; i++){
			if(num[i] == num[i+1]){
				int left = target - num[i] - num[i+1];
				if(table.count(left)){
					for(int k = 0; k < table[left].size(); k++)
						if(table[left][k] > i+1){
							int third = num[table[left][k]];
							int fourth = left - third;
							result.push_back(vector<int>{num[i], num[i+1], third, fourth});
						}
				}
				while(i < n - 1 && num[i] == num[i+1]) i++;
				i--;
				continue;
			}
			for(int j = i + 1; j < n; j++){
				if(j < n - 1 && num[j] == num[j+1]){
					int left = target - num[i] - num[j];
					if(table.count(left)){
						for(int k = 0; k < table[left].size(); k++)
							if(table[left][k] > j){
								int third = num[table[left][k]];
								int fourth = left - third;
								result.push_back(vector<int>{num[i], num[j], third, fourth});
							}
					}
					while(j < n - 1 && num[j] == num[j+1]) j++;
					continue;
				}
				int left = target - num[i] - num[j];
				if(table.count(left)){
					for(int k = 0; k < table[left].size(); k++)
						if(table[left][k] > j){
							int third = num[table[left][k]];
							int fourth = left - third;
							result.push_back(vector<int>{num[i], num[j], third, fourth});
						}
				}
			}
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	int A[] = {0,0,0,0};
	//int A[] = {91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
	vector<int> data(begin(A), end(A));
	//for(int i = 0; i < 200; i++)
	//vector<vector<int> > ret = sl.fourSum(data, -236727523);
	vector<vector<int> > ret = sl.fourSum(data, 0);
	
	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++){
			cout<<ret[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;

}
