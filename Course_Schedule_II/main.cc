#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {

public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> result;
		vector<int> input(numCourses, 0);
		vector<vector<int> > graph(numCourses, vector<int>());
		for(auto ele : prerequisites){
			input[ele.first]++;
			graph[ele.second].push_back(ele.first);
		}
		queue<int> q;
		for(int i = 0; i < input.size(); i++)
			if(input[i] == 0)	q.push(i);
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			result.push_back(cur);
			for(auto ele : graph[cur])
				if(--input[ele] == 0)	q.push(ele);
		}
		return result.size() == numCourses? result : vector<int>();
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<pair<int, int> > prerequisites;
	prerequisites.push_back(make_pair(1,0));
	prerequisites.push_back(make_pair(1,2));
	prerequisites.push_back(make_pair(3,1));
	prerequisites.push_back(make_pair(3,2));

	for(auto ele : sl.findOrder(4, prerequisites))
		cout<<ele<<" ";
	cout<<endl;

	return 0;

}
