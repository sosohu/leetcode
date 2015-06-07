#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {

public:

	vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings){
		vector<pair<int, int> > result;
		priority_queue<pair<int,int> >	q; // <height, right>
		int pos = 0, x, h, len = buildings.size();
		while(pos < len || !q.empty()){
			x = q.empty()? buildings[pos][0] : q.top().second;
			if(pos >= len || x < buildings[pos][0]){
				while(!q.empty() && q.top().second <= x)	q.pop();
			}else{
				x = buildings[pos][0];
				while(pos < len && x == buildings[pos][0]){
					q.push(make_pair(buildings[pos][2], buildings[pos][1]));
					pos++;
				}
			}
			h = q.empty()? 0 : q.top().first;
			if(result.empty() || result.back().second != h)
				result.push_back(make_pair(x, h));
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> > buildings
	 {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
	//{{3,7,8},{3,8,7},{3,9,6},{3,10,5},{3,11,4},{3,12,3},{3,13,2},{3,14,1}};

	vector<pair<int, int> > result = sl.getSkyline(buildings);
	for(auto ele : result)
		cout<<ele.first<<","<<ele.second<<endl;

	return 0;

}
