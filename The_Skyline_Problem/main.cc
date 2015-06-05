#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


class Solution {

public:

	void mergeFind(vector<vector<int> > buildings, vector<vector<int> > &piece,
					int begin, int end){
		if(begin > end)	return;
		if(begin == end){
			piece.push_back(buildings[begin]);
			return;
		}
		int pos = (begin + end) / 2;
		vector<vector<int> >  left, right;
		mergeFind(buildings, left, begin, pos);
		mergeFind(buildings, right, pos+1, end);
		int i = 0, j = 0;
		int l, r, h;
		while(i < left.size() && j < right.size()){
			if(left[i][0] < right[j][0]){
				if(left[i][1] <= right[j][0]){
					piece.push_back(left[i]);
					i++;
				}else{
					piece.push_back(vector<int>{left[i][0], right[j][0], left[i][2]});
					left[i][0] = right[j][0];
				}
			}else if(left[i][0] == right[j][0]){
				if(left[i][2] > right[j][2]){
					if(left[i][1] < right[j][1]){
						piece.push_back(left[i]);
						right[j][0] = left[i][1];
						i++;
					}else{
						piece.push_back(vector<int>{left[i][0], right[j][1], left[i][2]});
						left[i][0] = right[j][1];
						j++;
					}
				}else{
					if(left[i][1] < right[j][1]){
						piece.push_back(vector<int>{left[i][0], left[i][1], right[j][2]});
						right[j][0] = left[i][1];
						i++;
					}else{
						piece.push_back(right[j]);
						left[i][0] = right[j][1];
						j++;
					}
				}
			}else{
				if(right[j][1] <= left[i][0]){
					piece.push_back(right[j]);
					j++;
				}else{
					piece.push_back(vector<int>{right[j][0], left[i][0], right[j][2]});
					right[j][0] = left[i][0];
				}
			}
		}
		if(i < left.size())
			piece.insert(piece.end(), left.begin() + i, left.end());
		if(j < right.size())
			piece.insert(piece.end(), right.begin() + j, right.end());
	}

	vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings){
		vector<pair<int, int> > result;
		if(buildings.size() == 0)	return result;
		vector<vector<int> > piece;
		mergeFind(buildings, piece, 0, buildings.size() - 1);
		for(int i = 0; i < piece.size(); i++){
			if(i > 0 && piece[i][2] == piece[i-1][2] && piece[i][0] == piece[i-1][1])
				continue;
			if(i != 0 && piece[i][0] != piece[i-1][1])
				result.push_back(make_pair(piece[i-1][1], 0));
			result.push_back(make_pair(piece[i][0], piece[i][2]));
			if(i == piece.size() - 1)
				result.push_back(make_pair(piece[i][1], 0));
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
