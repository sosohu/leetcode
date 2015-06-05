#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


class Solution {

public:

	void mergeFind(vector<vector<int> > buildings, vector<vector<int> > &piece,
					int begin, int end, int left_edge, int right_edge){
		if(begin > end)	return;
		for(int i = begin; i <= end; i++){
			buildings[i][0] = max(buildings[i][0], left_edge);
			buildings[i][1] = min(buildings[i][1], right_edge);
		}
		if(begin == end){
			if(buildings[begin][0] != buildings[begin][1])
				piece.push_back(buildings[begin]);
			return;
		}
		

		vector<vector<int> >  right;
		mergeFind(buildings, piece, begin, pos, left_edge, l);
		if(r == buildings[pos][1])	pos++;	
		mergeFind(buildings, right, pos, end, r, right_edge);
		piece.push_back(vector<int>{l, r, h});
		piece.insert(piece.end(), right.begin(), right.end());
	}

	vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings){
		vector<pair<int, int> > result;
		if(buildings.size() == 0)	return result;
		vector<vector<int> > piece;
		mergeFind(buildings, piece, 0, buildings.size() - 1, 0, INT_MAX);
		for(int i = 0; i < piece.size(); i++){
			if(i > 0 && piece[i][2] == piece[i-1][2] && piece[i][0] == piece[i-1][1])
				continue;
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
	vector<vector<int> > buildings{{3,7,8},{3,8,7},{3,9,6},{3,10,5},{3,11,4},{3,12,3},{3,13,2},{3,14,1}};

	//{ {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
	vector<pair<int, int> > result = sl.getSkyline(buildings);
	for(auto ele : result)
		cout<<ele.first<<","<<ele.second<<endl;

	return 0;

}
