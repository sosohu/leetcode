#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

	vector<vector<int> > recursion(int n, int pos, vector<vector<bool> > &mark) {
		vector<vector<int> > data;
		if(pos == 0){
			for(int i = 0; i < mark[0].size(); i++)
				if(mark[0][i]){
					data.push_back(vector<int>(1, i));
				}
			return data;
		}

		vector<vector<int> > sub_data;
		vector<vector<bool> > sub_mark;
		for(int i = 0; i < mark[pos].size(); i++){
			if(mark[pos][i]){
				sub_mark = mark;
				for(int j = 0; j < mark[pos].size(); j++){
					sub_mark[j][i] = false;
					if(i-j >= 0 && pos - j >= 0){
						sub_mark[pos-j][i-j] = false;
					}
					if(i+j < n && pos - j >= 0){
						sub_mark[pos-j][i+j] = false;
					}
				}
				sub_data = recursion(n, pos-1, sub_mark);
				if(sub_data.size()){
					for(int k = 0; k < sub_data.size(); k++){
						sub_data[k].push_back(i);
						data.push_back(sub_data[k]);
					}
				}
			}
		}
		return data;
    }

	vector<vector<string> > solveNQueens_1st(int n) {
		vector<vector<bool> > mark(n, vector<bool>(n, true));
		vector<vector<int> > data =  recursion(n, n-1, mark);
		vector<vector<string> > ret;
		

		for(int i = 0; i < data.size(); i++){
			vector<string> vec(data[i].size(), "");
			for(int j = 0; j < data[i].size(); j++){
				for(int k = 0; k < data[i][j]; k++)
					vec[j] = vec[j] + ".";
				vec[j] = vec[j] + "Q";
				for(int k = data[i][j] + 1; k < n; k++)
					vec[j] = vec[j] + ".";
			}
			ret.push_back(vec);
		}
		return ret;
	}

	bool isSafe(vector<pair<int, int> > &queens, int i, int j){
		for(int k = 0; k < queens.size(); k++){
			int x = queens[k].first, y = queens[k].second;
			if(x == i || y == j || abs(i - x) == abs(j - y))
				return false;
		}
		return true;
	}

	void backtrack(vector<vector<string> > &result, vector<pair<int, int> > &queens,
					vector<string> &track, int row, int row_num){
		if(row == row_num){
			result.push_back(track);
			return;
		}
		string lines(row_num, '.');
		for(int i = 0; i < row_num; i++){
			if(isSafe(queens, row, i)){
				queens.push_back(make_pair(row, i));
				lines[i] = 'Q';
				track.push_back(lines);
				backtrack(result, queens, track, row+1, row_num);
				track.pop_back();
				lines[i] = '.';
				queens.pop_back();
			}
		}
	}

	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > result;
		if(n <= 0)	return result;
		vector<pair<int, int> > queens;
		vector<string> track;
		backtrack(result, queens, track, 0, n);
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	
    vector<vector<string> > ret = sl.solveNQueens(4);
	
	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<endl;
		cout<<endl;
	}

	return 0;

}
