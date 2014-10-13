#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {

public:

	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		int size = intervals.size();
		vector<Interval> data;
		if(size == 0){
			data.push_back(newInterval);
			return data;
		}
		int start = newInterval.start;
		int end = newInterval.end;
		int pos_st, pos_ed;
		bool st_has = false, ed_has = false;
		
		int i;
		for(i = 0; i < size; i++){
			if(intervals[i].end >= start && !st_has){
				pos_st = i;
				st_has = true;
			}
			if(intervals[i].end >= end && !ed_has){
				pos_ed = i;
				ed_has = true;
			}
			if(st_has && ed_has)
				break;
		}
		
		if(i == size){
			if(!st_has){
				data = intervals;
				data.push_back(newInterval);
				return data;
			}else{
				for(int j = 0; j <= pos_st; j++)
					data.push_back(intervals[j]);
				data[pos_st].end = end;
				if(start < data[pos_st].start)
					data[pos_st].start = start;
				return data;
			}
		}

		if(pos_st == pos_ed){
			if(start >= intervals[pos_st].start){
				data = intervals;
				return data;
			}
			else{
				if(end >= intervals[pos_st].start){
					data = intervals;
					data[pos_st].start = start;
					return data;
				}else{
					for(int j = 0; j < pos_st; j++)
						data.push_back(intervals[j]);
					data.push_back(newInterval);
					for(int j = pos_st; j < size; j++)
						data.push_back(intervals[j]);
					return data;
				}
			}
		}

		for(int j = 0; j < pos_st; j++)
			data.push_back(intervals[j]);
		data.push_back(intervals[pos_st]);
		if(start < intervals[pos_st].start)
			data[pos_st].start = start;
		if(end >= intervals[pos_ed].start)		
			data[pos_st].end = intervals[pos_ed].end;
		else{
			data[pos_st].end = end;
			data.push_back(intervals[pos_ed]);
		}

		for(int j = pos_ed + 1; j < size; j++)
			data.push_back(intervals[j]);
		return data;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<Interval> intervals(3, Interval(0,0));
	intervals[0] = Interval(1,4);	
	intervals[1] = Interval(7,12);	
	intervals[2] = Interval(14,16);	
	
	Interval newInterval(0,5);

	vector<Interval> ret = sl.insert(intervals, newInterval);
	
	for(int i = 0; i < ret.size(); i++)
		cout<<ret[i].start<<" "<<ret[i].end<<endl;

	return 0;

}
