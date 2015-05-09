#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

void print(UndirectedGraphNode* data, bool is_free = false){
	UndirectedGraphNode* pos = data;
	stack<UndirectedGraphNode*> s;
	map<UndirectedGraphNode*, int> mark;
	s.push(data);
	int len;
	cout<<"******PRINT MSG******"<<endl;
	while(!s.empty()){
		pos = s.top();
		s.pop();
		len = pos->neighbors.size();
		cout<<"++++++++++++++"<<endl;
		cout<<"point "<<pos<<endl;
		cout<<"label "<<pos->label<<endl;
		mark[pos] = 1;
		for(int i = 0; i < len ; i++){
			cout<<"neighbors "<<pos->neighbors[i]->label<<endl;
			if(mark.count(pos->neighbors[i]) != 1)
				s.push(pos->neighbors[i]);
		}
		//if(is_free)
		//	delete pos;
		cout<<"--------------"<<endl;
	}
}


class Solution {

public:

	void recursion(UndirectedGraphNode *root, UndirectedGraphNode *&ret, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &find){
		if(root == NULL){
			ret = NULL;
			return;
		}
		//if(find.count(root) == 1)	return;
		int size = root->neighbors.size();
		ret = new UndirectedGraphNode(1);
		ret->label = root->label;
		find[root] = ret;
		for(int i = 0; i < size; i++){
			if(root->neighbors[i]->label == root->label){
				ret->neighbors.push_back(ret);
			}else{
				ret->neighbors.push_back(NULL);
				if(find.count(root->neighbors[i]) == 1){
					ret->neighbors[i] = find[root->neighbors[i]];
				}else{
					recursion(root->neighbors[i], ret->neighbors[i], find);
				}
			}
		}
	}

	UndirectedGraphNode *cloneGraph_1st(UndirectedGraphNode *node) {
		if(node == NULL) return NULL;
		UndirectedGraphNode *ret;
		unordered_map <UndirectedGraphNode*, UndirectedGraphNode*> find;
		recursion(node, ret, find);
		return ret;
    }

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(!node)	return NULL;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>	table;
		unordered_set<UndirectedGraphNode*> visited;
		queue<UndirectedGraphNode*> q;
		q.push(node);
		UndirectedGraphNode *new_pos, *pos;
		while(!q.empty()){
			pos = q.front();
			q.pop();
			new_pos = new UndirectedGraphNode(pos->label);
			table[pos] = new_pos;
			for(int i = 0; i < pos->neighbors.size(); i++){
				if(table.count(pos->neighbors[i]) == 0){
					q.push(pos->neighbors[i]);
				}
			}
		}
		q.push(node);
		visited.insert(node);
		while(!q.empty()){
			pos = q.front();
			q.pop();
			for(int i = 0; i < pos->neighbors.size(); i++){
				table[pos]->neighbors.push_back(table[pos->neighbors[i]]);
				if(visited.count(pos->neighbors[i]) == 0){
					q.push(pos->neighbors[i]);
					visited.insert(pos->neighbors[i]);
				}
			}
		}
		return table[node];
	}

};


int main(int argc, char** argv)
{
	Solution sl;
    UndirectedGraphNode node(-1);

	node.neighbors.push_back(&node);
	node.neighbors.push_back(&node);

	print(&node);
	
	UndirectedGraphNode* ret = sl.cloneGraph(&node);
	
	print(ret, true);

	return 0;

}
