#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {

public:

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int> > g(numCourses, vector<int>());
		vector<bool> visited(numCourses, false);
		vector<int> pre_count(numCourses, 0);
		for(int i = 0; i < prerequisites.size(); i++){
			g[prerequisites[i][1]].push_back(prerequisites[i][0]);
			pre_count[prerequisites[i][0]]++;
		}
		queue<int> pre;
		for(int i = 0; i < numCourses; i++)
			if(!pre_count[i]){
				pre.push(i);
				visited[i] = true;
		}
		while(!pre.empty()){
			int pos = pre.front();
			pre.pop();
			for(int i = 0; i < g[pos].size(); i++){
				pre_count[g[pos][i]]--;
				if(pre_count[g[pos][i]] < 0)	return false;
				if(pre_count[g[pos][i]] == 0){
					pre.push(g[pos][i]);
					visited[g[pos][i]] = true;
				}
			}
		}
		for(int i = 0; i < numCourses; i++)
			if(!visited[i])	return false;
		return true;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<vector<int> > prerequisites{{2,0}, {2,1}};
	cout<<sl.canFinish(3, prerequisites)<<endl;

	return 0;

}
