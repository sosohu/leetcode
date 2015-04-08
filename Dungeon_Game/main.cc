#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<vector<int> >& data, string msg = ""){
	cout<<"print "<<msg<<endl;
	for(auto line : data){
		for(auto ele : line)
			cout<<ele<<" ";
		cout<<endl;
	}
}

class Solution {

public:

	int makeDp(int data){
		return data < 0? -data : 0;
	}

	int calculateMinimumHP(vector<vector<int> > &dungeon) {
		int n = dungeon.size();
		if(n == 0)	return 0;
		int m = dungeon[0].size();
		vector<vector<int> > dp(dungeon);
		vector<vector<int> > cost(dungeon);
		dp[0][0] = makeDp(dungeon[0][0]);
		for(int j = 1; j < m; j++){
			if(dungeon[0][j] >= 0){
				dp[0][j] = dp[0][j-1];
			}else{
				dp[0][j] = max(dp[0][j-1], makeDp(cost[0][j-1] + dungeon[0][j]));
			}
			cost[0][j] = cost[0][j-1] + dungeon[0][j];
		}
		for(int i = 1; i < n; i++){
			if(dungeon[i][0] >= 0){
				dp[i][0] = dp[i-1][0];
			}else{
				dp[i][0] = max(dp[i-1][0], makeDp(cost[i-1][0] + dungeon[i][0]));
			}
			cost[i][0] = cost[i-1][0] + dungeon[i][0];
		}
		for(int i = 1; i < n; i++)
			for(int j = 1; j < m; j++){
				if(dungeon[i][j] >= 0){
					dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
				}else{
					dp[i][j] = min(max(dp[i-1][j], makeDp(cost[i-1][j] + dungeon[i][j])),
									max(dp[i][j-1], makeDp(cost[i][j-1] + dungeon[i][j])));
				}
				if(max(dp[i-1][j], makeDp(cost[i-1][j] + dungeon[i][j])) 
								< max(dp[i][j-1], makeDp(cost[i][j-1] + dungeon[i][j]))){
					cost[i][j] = cost[i-1][j] + dungeon[i][j];
				}else{
					cost[i][j] = cost[i][j-1] + dungeon[i][j];
				}
			
			}
		print(dungeon, "dungeon");
		print(dp, "dp");
		print(cost, "cost");
		return dp[n-1][m-1] + 1;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> >data = {{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}};
	
	cout<<"Result  :("<<sl.calculateMinimumHP(data)<<")"<<endl;

	return 0;

}
