#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>

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

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node == NULL) return NULL;
		UndirectedGraphNode *ret;
		unordered_map <UndirectedGraphNode*, UndirectedGraphNode*> find;
		recursion(node, ret, find);
		return ret;
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
