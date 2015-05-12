#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>

using namespace std;


class Solution {

public:

	int largestRectangleArea_1st(vector<int> &height) {
		int len = height.size();
		if(len == 0)	return 0;

		vector<int> left(len, 0), right(len, 0);

		for(int i = 1; i < len; i++){
			for(int j = i - 1; j >=0; j--){
				if(height[i] <= height[j]){
					left[i] = left[i] + left[j] + 1;
					j = j - left[j];
				}else{
					break;
				}
			}
		}
		for(int i = len - 2; i >= 0; i--){
			for(int j = i+1; j < len; j++){
				if(height[i] <= height[j]){
					right[i] = right[i] + right[j] + 1;
					j = j + right[j];
				}else{
					break;
				}
			}
		}
		int data = 0, tmp;

		for(int i = 0; i < len; i++){
			tmp = height[i] * (left[i] + right[i] + 1);
			if(data < tmp){
				data = tmp;
			}
		}
		return data;
    }

	/*元素大于等于栈顶元素时候放入栈，小于时候处理*/
	int largestRectangleArea(vector<int> &height) {
		if(height.size() == 0)	return 0;
		if(height.size() == 1)	return height[0];
		stack<pair<int, int> > s;
		s.push(make_pair(height[0], 0));
		int result = INT_MIN;
		for(int i = 1; i < height.size(); i++){
			while(height[i] < s.top().first){
				pair<int, int> cur = s.top();
				s.pop();
				if(!s.empty()){
					if(result < cur.first * (i - s.top().second - 1))
						result = cur.first * (i - s.top().second - 1);
				}else{
					if(result < cur.first * i)
						result = cur.first * i;
					break;
				}
			}
			s.push(make_pair(height[i], i));
		}
		/*栈中元素按照非降序排列*/
		int index = s.top().second;
		while(!s.empty()){
			pair<int, int> cur = s.top();
			s.pop();
			if(!s.empty()){
				if(result < cur.first * (index - s.top().second))
					result = cur.first * (index - s.top().second);
			}else{
				if(result < cur.first * (index + 1))
					result = cur.first * (index + 1);
			}
		}
		return result;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	int data[] = {9,0};
	vector<int> height(begin(data), end(data));

	int ret = sl.largestRectangleArea(height);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
