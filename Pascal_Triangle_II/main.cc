#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


class Solution {

public:
	
	vector<int> getRow_1st(int rowIndex) {
		vector<int> data;
		if(rowIndex == 0){
			data.push_back(1);
			return data;
		}

		queue<int> temp;
		temp.push(1);
		temp.push(1);
		
		int first, second;
		for(int i = 2; i < rowIndex + 1; i++){
			temp.push(1);
			first = temp.front();
			temp.pop();
			for(int j = 1; j < i; j++){
				second = temp.front();
				temp.pop();
				temp.push(first + second);
				first = second;
			}
			temp.push(1);
		}
		int tmp;
		int size = temp.size();
		for(int i = 0; i < size; i++){
			tmp = temp.front();
			temp.pop();
			data.push_back(tmp);
		}
		return data;
    }

	vector<int> getRow(int rowIndex) {
		rowIndex++;
		if(rowIndex <= 0)	return vector<int>();
		vector<int> result{1};
		for(int i = 1; i < rowIndex; i++){
			vector<int> cur;
			cur.push_back(1);
			for(int j = 0; j < result.size() - 1; j++)
				cur.push_back(result[j] + result[j+1]);
			cur.push_back(1);
			result.swap(cur);
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> ret = sl.getRow(3);
	
	for(int i = 0; i < ret.size(); i++){
		cout<<ret[i]<<" ";
	}	
	cout<<endl;

	return 0;

}
