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
		return data < 0? -data : 1;
	}

	int calculateMinimumHP(vector<vector<int> > &dungeon) {
		int n = dungeon.size();
		if(n == 0)	return 0;
		int m = dungeon[0].size();
		vector<vector<int> > dp(dungeon);
		for(int i = n - 1; i >= 0; i--)
			for(int j = m - 1; j >= 0; j--){
				if( i == n - 1 && j == m - 1)
					dp[i][j] = dungeon[i][j] < 0? -dungeon[i][j] + 1 : 1;
				else{
					if(i == n - 1){
						dp[i][j] = makeDp(dungeon[i][j] - dp[i][j+1]);
					}else if(j == m - 1){
						dp[i][j] = makeDp(dungeon[i][j] - dp[i+1][j]);
					}else{
						int right = makeDp(dungeon[i][j] - dp[i][j+1]);
						int down = makeDp(dungeon[i][j] - dp[i+1][j]);
						dp[i][j] = min(right, down);
					}
				}	
			}
		//print(dungeon, "dungeon");
		//print(dp, "dp");
		return dp[0][0];
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> >data = {{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}};
	
	cout<<"Result  :("<<sl.calculateMinimumHP(data)<<")"<<endl;

	return 0;

}
