#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:
	void parse(string &input, vector<int> &nums, vector<char> &op){
		int pos = 0, n = input.size();
		while(pos < n){
			int count = 0;
			while(pos < n && input[pos] <= '9' && input[pos] >= '0'){
				count = count*10 + input[pos] - '0';
				pos++;
			}
			nums.push_back(count);
			if(pos < n){
				op.push_back(input[pos]);
				pos++;
			}
		}
	}

	long long makeOp(long long a, long long b, char op){
		switch(op){
			case '+':	return a + b;
			case '-':	return a - b;
			case '*':	return a * b;
		}
	}

public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> nums;
		vector<char>	op;
		parse(input, nums, op);
		int n = nums.size();
		vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>()));
		for(int i = 0; i < n; i++)
			dp[i][i] = vector<long long>(1, nums[i]);
		for(int len = 2; len <= n; len++){
			for(int i = 0; i <= n - len; i++){
				for(int j = i; j < i + len - 1; j++){
					for(int p = 0; p < dp[i][j].size(); p++){
						for(int q = 0; q < dp[j+1][i+len-1].size(); q++){
							dp[i][i+len-1].push_back(makeOp(dp[i][j][p], dp[j+1][i+len-1][q], op[j]));
						}
					}
				}
			}
		}
		vector<int> res;
		for(auto ele : dp[0][n-1])
			res.push_back(ele);
		return res;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	string input("2*3-4*5");
	vector<int> res = sl.diffWaysToCompute(input);	
	for(auto ele : res)
		cout<<ele<<endl;

	return 0;

}
