#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


class Solution {

public:

	int recursion(vector<vector<int> >& triangle, int level, int pos, int size, vector<int>& deliver){
		int val = triangle[level][pos];

		if(level == size -1){
			deliver[0] = val;
			return val;
		}
		int left = 0, right = 0;
		
		if(pos == 0)
			left = recursion(triangle, level + 1, pos, size, deliver);
		else
			left = deliver[size - 1 - level];

		right = recursion(triangle, level + 1, pos + 1, size, deliver);
		deliver[size - 1 - level] = right;

		int ret =  left < right? left : right;
		
		return ret + val;
		
	}

	int minimumTotal_1st(vector<vector<int> > &triangle) {
		int size = triangle.size();
		if(size == 0)	return 0;
		vector<int> deliver;
		for(int i = 0; i < size; i++)
			deliver.push_back(0);
		return recursion(triangle, 0, 0, size, deliver);
    }

	int minimumTotal(vector<vector<int> > &triangle) {
		int n = triangle.size();
		if( n == 0)	return 0;
		vector<int> odp(triangle[0]);
		vector<int> ndp(triangle[0]);
		for(int i = 1; i < n; i++){
			odp = ndp;
			ndp.clear();
			ndp.resize(i+1);
			for(int j = 0; j < triangle[i].size(); j++){
				ndp[j] = triangle[i][j] + min((j == 0? INT_MAX : odp[j-1]), 
								(j == triangle[i].size()-1? INT_MAX : odp[j]));
			}
		}
		auto iter = min_element(ndp.begin(), ndp.end());
		return *iter;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> > tree;
	//int data[] = {1,2,3,4,5,6,7,8,9,10};
	int data[] = {-7,-2,1,-5,-5,9,-4,-5,4,4,-6,-6,2,-1,-5,3,7,8,-3,7,-9,-9,-1,-9,6,9,0,7,-7,0,-6,-8,7,1,-4,9,-3,2,-6,-9,-7,-6,-9,4,0,-8,-6,-3,-9,-2,-6,7,-5,0,7,-9,-1,-2,4,-2,4,4,-1,2,-5,5,1,1,-6,1,-2,-4,4,-2,6,-6,0,6,-3,-3,-6,-2,-6,-2,7,-9,-5,-7,-5,5,1};
	int i = 0, count = 1;
	//while(i < 10){
	while(i < 91){
		vector<int> vec;
		for(int j = i; j < i + count; j++){
			vec.push_back(data[j]);
			cout<<data[j]<<" ";
		}
		cout<<endl;
		tree.push_back(vec);
		i = i + count;
		count++;
	}

    int ret = sl.minimumTotal(tree);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
