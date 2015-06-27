#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;


class Solution {

public:

	bool getNext(const string &s, int &pos, pair<bool, int> &next, bool stay){
		if(stay)	return true;
		if(pos == s.size())	return false;
		if(s[pos] <= '9' && s[pos] >= '0'){
			int num = 0;
			while(pos < s.size() && s[pos] <= '9' && s[pos] >= '0'){
				num = num*10 + s[pos++] - '0';
			}
			next.first = true;
			next.second = num;
		}else{
			next.first = false;
			next.second = s[pos++];
		}
		return true;
	}

	bool isEle(pair<bool, int> &ele, char c){
		return ele.first == false && ele.second == c;
	}

	int calculate(string s) {
		stack<pair<bool, int> > sum; // true is num, false is other char represented by ascii
		int pos = 0;
		pair<bool, int> next, pre;
		bool stay = false;
		while(getNext(s, pos, next, stay)){
			stay = false;
			if(next.first){
				if(sum.empty() || isEle(sum.top(), '(')){
					sum.push(next);
				}else{
					bool add = isEle(sum.top(), '+');
					assert(!sum.empty());
					sum.pop();
					pre = sum.top();
					sum.pop();
					sum.push(make_pair(true, pre.second + (add? next.second : -next.second)));
				}
			}else{
				switch(next.second){
					case	' ':	break;
					case	'+':	if(!sum.empty() && !isEle(sum.top(), '('))	sum.push(next);
									break;
					case 	'-':	if(sum.empty() || isEle(sum.top(), '('))	
										sum.push(make_pair(true, 0));
									sum.push(next);	break;
					case	'(':	sum.push(next); break;
					case	')':	next = sum.top(); sum.pop(); sum.pop(); stay = true; break;
					default:	;
				}
			}
		}
		return sum.top().second;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	cout<<sl.calculate("(1+(4+5+2)-3)+(6+8)")<<endl;

	return 0;

}
