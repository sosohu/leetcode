#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:

	long long makeOp(long long a, long long b, char op){
		switch(op){
			case '+':	return a + b;
			case '-':	return a - b;
			case '*':	return a * b;
		}
	}
	void backtrace(string &num, vector<string> &res, string &path, 
					long long target, stack<long long> &data, stack<char> &op, long long pos){
		if(pos == num.size()){
			long long cur = 0;
			if()
			if(cur == target){
				res.push_back(path);
			}
			return;
		}
		if(num[pos] == 0){

		}
		long long factor = 0;
		string tmp = path;
		for(long long i = pos; i < num.size(); i++){
			path = tmp;
			factor = factor*10 + num[i] - '0';
			//+ / -
			long long top_data = data.top();
			char top_op = op.top();
			long long res = makeOp(factor, top_data, top_op);
			data.pop();
			data.push(res);
			op.pop();
			op.push('+');
		}
	}

    vector<string> addOperators(string num, long long target) {
		vector<string> res;
		string path;
		long long cur = 0;
		stack<char> op;
		op.push_back('+');
		stack<long long> data;
		data.push_back(0);
		backtrace(num, res, path, target, data, op, 0);
    }
};

int main(long long argc, char** argv)
{
	Solution sl;

	return 0;
}
