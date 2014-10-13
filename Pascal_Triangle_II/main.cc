#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


class Solution {

public:
	
	vector<int> getRow(int rowIndex) {
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

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> ret = sl.getRow(15);
	
	for(int i = 0; i < ret.size(); i++){
		cout<<ret[i]<<" ";
	}	
	cout<<endl;

	return 0;

}
