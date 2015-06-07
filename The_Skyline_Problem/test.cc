#include <queue>
#include <iostream>

using namespace std;

int main(){
	priority_queue<pair<int,int> > q;
	q.push(make_pair(2,3));
	q.push(make_pair(2,4));
	q.push(make_pair(1,4));
	q.push(make_pair(5,4));
	while(!q.empty()){
		cout<<q.top().first<<","<<q.top().second<<endl;
		q.pop();
	}
}
