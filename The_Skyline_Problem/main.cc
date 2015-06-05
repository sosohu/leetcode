#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


class Solution {

public:

	void mergeFind(vector<vector<int> > &buildings, vector<vector<int> > &piece,
					int begin, int end, int left_edge, int right_edge){
		if(begin > end)	return;
		for(int i = begin; i <= end; i++){
			buildings[i][0] = max(buildings[i][0], left_edge);
			buildings[i][1] = min(buildings[i][1], right_edge);
		}
		if(begin == end){
			piece.push_back(buildings[begin]);
			return;
		}
		int pos = begin, highest = buildings[begin][2];
		for(int i = begin; i <= end; i++)
			if(highest < buildings[i][2]){
				highest = buildings[i][2];
				pos = i;
			}
		vector<vector<int> >  right;
		mergeFind(buildings, piece, begin, pos - 1, left_edge, buildings[pos][0]);
		mergeFind(buildings, right, pos + 1, end, buildings[pos][1], right_edge);
		piece.push_back(buildings[pos]);
		piece.insert(piece.end(), right.begin(), right.end());
	}

	vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings){
		vector<pair<int, int> > result;
		if(buildings.size() == 0)	return result;
		vector<vector<int> > piece;
		mergeFind(buildings, piece, 0, buildings.size() - 1, 0, INT_MAX);
		for(int i = 0; i < piece.size(); i++){
			result.push_back(make_pair(piece[i][0], piece[i][2]));
			if(i == piece.size() - 1 || piece[i][1] != piece[i+1][0])
				result.push_back(make_pair(piece[i][1], 0));
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> > buildings{ {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
	vector<pair<int, int> > result = sl.getSkyline(buildings);
	for(auto ele : result)
		cout<<ele.first<<","<<ele.second<<endl;

	return 0;

}
