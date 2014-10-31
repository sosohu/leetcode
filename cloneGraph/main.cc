#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
	UndirectedGraphNode()  {};
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

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node == NULL) return NULL;
		UndirectedGraphNode* pos = node;
		UndirectedGraphNode* tmp;
		stack<UndirectedGraphNode*> s;
		s.push(pos);
		int len;
		while(!s.empty()){
			pos = s.top();
			s.pop();
			len = pos->neighbors.size();
			tmp = new UndirectedGraphNode(pos->label);
			pos->neighbors.push_back(tmp);
			for(int i = 0; i < len; i++){
				if(pos->neighbors[i] != pos){
					tmp = pos->neighbors[i];
					int tmp_len = tmp->neighbors.size();
					if(tmp_len == 0)
						s.push(tmp);
					else{
						if(!(tmp->neighbors[tmp_len - 1]->label == tmp->label 
							&& tmp->neighbors[tmp_len -1] != tmp))
							s.push(tmp);
					}
				}
			}
		}
		#ifndef DEBUG
		print(node);
		#endif
		s.push(node);
		UndirectedGraphNode* tmp_tmp;
		int len_len;
		len = node->neighbors.size();
		UndirectedGraphNode* ret = node->neighbors[len - 1];
		while(!s.empty()){
			pos = s.top();
			s.pop();
			len = pos->neighbors.size();
			tmp = pos->neighbors[len - 1];
			for(int i = 0; i < len - 1; i++){
				if(pos->neighbors[i] == pos){
					tmp->neighbors.push_back(tmp);
				}
				else{
					int long_len = pos->neighbors[i]->neighbors.size();
					UndirectedGraphNode* node_new = 
								pos->neighbors[i]->neighbors[long_len - 1];
					tmp->neighbors.push_back(node_new);
					tmp_tmp = pos->neighbors[i];
					len_len = tmp_tmp->neighbors.size();
					if(len_len > 1){
						if(tmp_tmp->neighbors[len_len - 1] != 
											tmp_tmp->neighbors[len_len - 2])
						s.push(tmp_tmp);
					}
				}
			}
			/*
			pos->neighbors.erase(pos->neighbors.begin() + len - 1, 
									pos->neighbors.end());
			*/
			pos->neighbors.push_back(pos->neighbors[len - 1]);
		}
		return ret;
    }

};


int main(int argc, char** argv)
{
	Solution sl;
	string s("  hello my world ada ");		
    UndirectedGraphNode node[10];

	node[0].label = -1;
	node[0].neighbors.push_back(&node[0]);
	node[0].neighbors.push_back(&node[0]);

	print(&node[0]);
	
	UndirectedGraphNode* ret = sl.cloneGraph(&node[0]);
	
	print(ret, true);

	return 0;

}
