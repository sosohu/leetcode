#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;


class Solution {

public:

	bool isNumber(const char *s) {
		int len = strlen(s);	
		vector<int> marke, mark_add, mark_minus, mark_point;
		int pos , start, end;
		pos = 0;
		while(pos < len){
			if(s[pos] != ' ')	
				break;
			pos++;
		}
		if(pos == len)	return false;
		start = pos;
		pos = len - 1;
		while(pos >= 0){
			if(s[pos] != ' ')	
				break;
			pos--;
		}
		end = pos;
		for(pos = start; pos <= end; pos++){
			switch(s[pos]){
				case 'e': marke.push_back(pos); break; 
				case '+': mark_add.push_back(pos); break; 
				case '-': mark_minus.push_back(pos); break; 
				case '.': mark_point.push_back(pos); break; 
				default:	if(!(s[pos] <= '9' && s[pos] >= '0'))
							return false;
			}
		}
		if(mark_point.size() > 1)	return false;
		if(mark_add.size() + mark_minus.size() > 2)	return false;
		if(marke.size() > 1)	return false;

		if(marke.size() == 1){
			if(marke[0] == start || marke[0] == end) return false;
			//if(s[marke[0] - 1] > '9' || s[marke[0] - 1] < '0' )	return false;
			//if(s[marke[0] + 1] > '9' || s[marke[0] + 1] < '0' )	return false;
			//if(mark_point.size() && mark_point[0] == start) return false;
			//if(mark_point.size() && mark_point[0] == marke[0] - 1) return false;
			//if(mark_point.size() && mark_point[0] == marke[0] + 1) return false;
			//if(mark_point.size() && mark_point[0] == end) return false;
			if(mark_point.size() == 1 && mark_point[0] == start &&
				start == marke[0] - 1){
				return false;
			}
			if(mark_point.size() == 1 && mark_point[0] <= end &&
				mark_point[0] >= marke[0] + 1){
				return false;
			}
			if(mark_add.size() + mark_minus.size() == 2){
				if(s[start] != '+' && s[start] != '-')	return false;
				if(s[marke[0] + 1] != '+' && s[marke[0]+1] != '-')	return false;
				if(start + 1 == marke[0])	return false;
				if(end - 1 == marke[0])	return false;
			}
			if(mark_add.size() + mark_minus.size() == 1){
				if((s[start] != '+' && s[start] != '-')
					&& (s[marke[0] + 1] != '+' && s[marke[0]+1] != '-'))
					return false;

				if((s[start] == '+' || s[start] == '-') && start + 1 == marke[0])
					return false;
				if((s[marke[0]+1] == '+' || s[marke[0]+1] == '-') && end - 1 == marke[0])
					return false;
			}
		}else{
			if(mark_add.size() + mark_minus.size() > 1)	return false;
			if(mark_add.size() && mark_add[0] != start)	return false;
			if(mark_point.size() > 1)	return false;
			if(mark_point.size() == 1 && start == end){
				return false;
			}
			if(mark_minus.size() && mark_minus[0] != start)	return false;
			if(end - start + 1 == mark_add.size() + mark_minus.size() + mark_point.size())
				return false;
			//if(mark_point.size() && mark_point[0] == start) return false;
			//if(mark_point.size() && mark_point[0] == end) return false;
		}
		return true;
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	const char* s = "-.3e6";		
	bool ret = sl.isNumber(s);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
