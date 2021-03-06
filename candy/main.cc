#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

private:

inline int get(vector<int> ratings, int pos, int len){
			int right = 0;
			if(pos < len -1){
				if(ratings[pos] == ratings[pos + 1])
					right = 0;
				else{
					while(pos < len -1){
						if(ratings[pos] <= ratings[pos + 1])
							break;
						else{
							right++;
							pos++;
						}
					}
				}
			}
			return right;
}

public:

	int candy_1st(vector<int> &ratings) {
		int len = ratings.size();
		int left, right, pos, add, sum =0;
		int last_left, last_right;
		bool has_right;
		if(len == 1) return 1;
		for(int i = 0; i < len; i++){
			pos = i;
			left = 0;
			right = 0;
			has_right = false;
			if(pos > 0){
				if(ratings[pos] == ratings[pos - 1]){
					left = 0;
				}else{
					if(ratings[pos] < ratings[pos - 1]){
						right = last_right - 1;
						has_right = true;
						left = 0;
					}
					else{
						left = last_left + 1;
					}
				}
			}
			if(!has_right){
				pos = i;
				right = get(ratings, pos, len);
			}
			add = left > right? left : right;
			last_left = left;
			last_right = right;
			sum =  sum + add;
			cout<<"add "<<add<<endl;
		}	
		sum =  sum + len;
		return sum;
   }

	int candy(vector<int> &ratings) {
		int size = ratings.size();
		vector<int> left(size, 0), right(size, 0);
		for(int i = 1; i < size; i++)
			if(ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
			else	left[i] = 0;
		for(int i = size - 2; i >= 0; i--)
			if(ratings[i] > ratings[i+1]) right[i] = right[i+1] + 1;
			else	right[i] = 0;
		int sum = 0;
		for(int i = 0; i < size; i++)
			sum += max(left[i], right[i]) + 1;
		return sum;
	}

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<int> data;
	/*
	for(int i = 0; i < 10; i++){
		data.push_back(i);
	}

	for(int i = 0; i < 10; i++)
		cout<<data[i]<<" ";
	*/
		data.push_back(5);
		data.push_back(3);
		data.push_back(1);

	cout<<endl<<"Result  : "<<endl;
    cout<<sl.candy(data)<<endl;
	

	return 0;

}
