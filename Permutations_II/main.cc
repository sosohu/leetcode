#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
void print(vector<vector<T> > data, string str = ""){
	cout<<"PRINT "<<str<<endl;
	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size(); j++)
			cout<<data[i][j]<<" ";
		cout<<endl;
	}
}


class Solution {

	class mysort{
		public:
			bool operator()(int i, int j){
				return i < j;
			}
	} mysort;

public:

	vector<vector<int> > getall(vector<bool>& mark, int n, int times, int pos){
		vector<vector<int> > data;
		vector<vector<int> > sub_data;
		if(times == 0) return data;
		for(int i = pos; i + times <= n; i++){
			if(mark[i]){
				if(times == 1){
					data.push_back(vector<int>(1, i));
					continue;
				}
				sub_data = getall(mark, n, times - 1, i + 1);
				for(int j = 0; j < sub_data.size(); j++){
					sub_data[j].push_back(i);
					data.push_back(sub_data[j]);	
				}
			}
		}
		return data;
	}	

	vector<vector<int> > posUnique(vector<int> &simple_num, vector<int> &count,
							       vector<bool> mark,	int n,  int sn, int pos){
		int times = count[pos];
		vector<vector<int> > cur;
		vector<vector<int> > data;
		vector<vector<int> > sub_data;

		cur = getall(mark, n, times, 0);
		//cout<<"pos "<<pos<<" times "<<times<<endl;
		//print(cur, "cur");

		if(pos == sn - 1)	return cur;

		vector<bool> mark_back;
		vector<int>  cur_line;
		for(int i = 0; i < cur.size(); i++){
			mark_back = mark;
			for(int j = 0; j < cur[i].size(); j++){
				mark_back[cur[i][j]] = false;
			}
			sub_data = posUnique(simple_num, count, mark_back, n, sn,  pos+1);
			for(int k = 0; k < sub_data.size(); k++){
				cur_line = cur[i];
				cur_line.insert(cur_line.end(), sub_data[k].begin(), sub_data[k].end());
				data.push_back(cur_line);
			}
		}
		return data;	
	}

	vector<vector<int> > permuteUnique(vector<int> &num) {
		int len = num.size();	
		vector<vector<int> > data;
		if(len == 0)	return data;

		sort(num.begin(), num.end(), mysort);
		
		vector<int> simple_num;
		vector<int> count;
		vector<bool> mark(len, true);

		simple_num.push_back(num[0]);
		count.push_back(1);
		int last = num[0];
		int pos = 0;
		for(int i = 1; i < len; i++){
			if(last == num[i]){
				count[pos]++;
			}else{
				last = num[i];
				simple_num.push_back(num[i]);
				count.push_back(1);
				pos++;
			}
		}
		//cout<<simple_num.size()<<endl;
		vector<vector<int> > seq = posUnique(simple_num, count, mark, len, simple_num.size(), 0);
		data = seq;
		for(int i = 0; i < seq.size(); i++){
			for(int j = 0; j < seq[i].size(); j++){
				data[i][seq[i][j]] = num[j];
			}
		}
		return data;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> data(4, 0);
	data[0] = 1;
	data[1] = 1;
	data[2] = 2;
	data[3] = 2;
    vector<vector<int> > ret = sl.permuteUnique(data);
	
	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<endl;
		cout<<endl;
	}
	cout<<ret.size()<<endl;

	return 0;

}
