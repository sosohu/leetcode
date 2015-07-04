#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    bool find(vector<int> &chair, vector<int> &occupied, int ele){
        for(int j = 0; j < 2; j++){
            if(occupied[j] && chair[j] == ele){
                occupied[j]++;
                return true;
            }
        }
        for(int j = 0; j < 2; j++){
            if(!occupied[j]){
                occupied[j]++;
                chair[j] = ele;
                return true;
            }
        }
        return false;
    }

    vector<int> majorityElement(vector<int>& nums) {
        vector<int> chair(2, 0), occupied(2, 0);
        for(int i = 0; i < nums.size(); i++){
            if(!find(chair, occupied, nums[i])){
                for(int j = 0; j < 2; j++){
                    --occupied[j];
                }
            }
        }
        vector<int> res;
        for(int i = 0; i < 2; i++)
            if(occupied[i]){
                int c = 0;
                for(int j = 0; j < nums.size(); j++){
                    if(chair[i] == nums[j]) c++;
                }
                if(c > nums.size()/3)   res.push_back(chair[i]);
            }
        return res;
    }

};

int main(int argc, char** argv)
{
	Solution sl;

	return 0;

}
