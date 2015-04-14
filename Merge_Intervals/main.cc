#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {

	class mysort{
		public:
			bool operator()(Interval a, Interval b){
				return a.start < b.start;
			}
	} mysort;

public:

	vector<Interval> merge_1st(vector<Interval> &intervals) {
		sort(intervals.begin(), intervals.end(), mysort);
		int len = intervals.size();
		vector<Interval> data;
		Interval tmp;
		if(len == 0)	return data;

		int last_start = intervals[0].start;
		int last_end = intervals[0].end;
		int start, end;
		data.push_back(intervals[0]);
		int count = 0;
		for(int i = 1; i < len; i++){
			start = intervals[i].start;
			end = intervals[i].end;
			if(start <= last_end){
				if(end > last_end){
					tmp.start = last_start;
					tmp.end = end;
					data[count].start = last_start;
					data[count].end = end;
					last_start = last_start;
					last_end = end;
				}
			}else{
				data.push_back(intervals[i]);
				count++;
				last_start = start;
				last_end = end;
			}
		}
		return data;
    }

	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> result;
		sort(intervals.begin(), intervals.end(), mysort);
		Interval cur;
		int pos = 0;
		while(pos < intervals.size()){
			cur = intervals[pos];
			pos++;
			while(pos < intervals.size() && cur.end >= intervals[pos].start){
				cur.end = max(cur.end, intervals[pos].end);
				pos++;
			}
			result.push_back(cur);
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<Interval> intervals(3, Interval(0,0));
	intervals[0] = Interval(4,5);	
	intervals[1] = Interval(1,4);	
	intervals[2] = Interval(0,1);	
	

	vector<Interval> ret = sl.merge(intervals);
	
	for(int i = 0; i < ret.size(); i++)
		cout<<ret[i].start<<" "<<ret[i].end<<endl;

	return 0;

}
