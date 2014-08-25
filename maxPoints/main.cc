#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DATA_SIZE 132

struct Point{
    int x;
    int y;

    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
private:
		struct Info{
			Point one; // one point of the line
			double k; // slope
			bool is_y;  // y axes
			bool is_same; // same point
			
			Info(){ is_same = false;}

			Info(Point one, double k, bool is_y = false) : one(one) , k(k), is_y(is_y) { is_same = false;}

			void set(Point one_arg, double k_arg, bool is_y_arg = false){
				one = one_arg;
				k = k_arg; 
				is_y = is_y_arg;
			}
			void set_same(bool arg){ is_same = arg;}
		} ;	

public:
	int maxPoints_Detail(vector<Point> &points, vector<Info>& max, vector<Info>& submax, int n, int& max_num, int& sub_num){
		double k;
		if(n == 2){
			Info info;
			if(points[1].x == points[0].x){	
				if(points[1].y != points[0].y)	
					info.set(points[0], 0, true);
				else{
					info.set(points[0], 0, false);
					info.set_same(true);
					max.push_back(info);
					max_num = 2;
					return 2;
				}
			}
			else{
				k = (points[1].y - points[0].y)*1.0 / (points[1].x - points[0].x);
				info.set(points[0], k);
			}

			max.push_back(info);
			max_num = 2;

			info.set(points[0], 0);
			submax.push_back(info);
			info.set(points[1], 0);
			submax.push_back(info);
			sub_num = 1;
			return 2;
		}	
		vector<Info> max_temp;
		vector<Info> sub_temp;
		maxPoints_Detail(points, max, submax, n -1, max_num , sub_num);
		for(int i = 0; i < max.size(); i++){	
			if(points[n -1].x == max[i].one.x){
				if(max[i].is_y || points[n - 1].y == max[i].one.y){
					max_temp.push_back(max[i]);
					max.erase(max.begin() + i);
				}
				continue;
			}
			if(max[i].is_same){
				k = (points[n -1].y - max[i].one.y)*1.0 / 
					(points[n -1].x - max[i].one.x);
				max[i].set_same(false);
				max[i].k = k;
				max_temp.push_back(max[i]);
				max[i].set_same(true);
				//max.erase(max.begin() + i);
				cout<<__LINE__<<" "<<k<<endl;
				continue;
			}
			if(max[i].is_y) continue;
			k = (points[n -1].y - max[i].one.y)*1.0 / 
				(points[n -1].x - max[i].one.x);
			if(k == max[i].k){
				max_temp.push_back(max[i]);
				max.erase(max.begin() + i);
				cout<<__LINE__<<" "<<k<<endl;
			}
		}
		if(!max_temp.empty()){
			submax = max;
			max.swap(max_temp);
			sub_num = max_num;
			max_num++;
			cout<<__LINE__<<" "<<max_num<<endl;
			return max_num;
		}
		// not in the max line, search in the sub line
		if(sub_num == 1){
			for(int i = 0; i < submax.size(); i++){	
				if(points[n -1].x == submax[i].one.x){
					if(points[n -1].y == submax[i].one.y)
						submax[i].is_same = true;
					else
						submax[i].is_y = true;
				}
				else{
					k = (points[n -1].y - submax[i].one.y)*1.0 / 
						(points[n -1].x - submax[i].one.x);
					submax[i].k = k;		
				}
			}		
			if(max_num == 2){
				max.insert(max.end(), submax.begin(), submax.end());
			}else{
				sub_num++;
			}
			Info info(points[n - 1], k);
			submax.push_back(info);
		}
		else{
			for(int i = 0; i < submax.size(); i++){	
				if(points[n -1].x == submax[i].one.x){
					if(submax[i].is_y || points[n - 1].y == submax[i].one.y){
						sub_temp.push_back(submax[i]);
						submax.erase(submax.begin() + i);
					}
					continue;
				}
				if(submax[i].is_same){
					k = (points[n -1].y - submax[i].one.y)*1.0 / 
						(points[n -1].x - submax[i].one.x);
					max[i].set_same(false);
					max[i].k = k;
					max_temp.push_back(max[i]);
					max[i].set_same(true);
					continue;
				}
				if(submax[i].is_y) continue;
				k = (points[n -1].y - submax[i].one.y)*1.0 / 
					(points[n -1].x - submax[i].one.x);
				if(submax[i].k == k){
					sub_temp.push_back(submax[i]);
					submax.erase(submax.begin() + i);
				}
			}
			if(!sub_temp.empty()){
				if(max_num == sub_num + 1){
					max.insert(max.end(), submax.begin(), submax.end());
				}else{
					submax.swap(sub_temp);
				}
				sub_num++;
			}
		}

		return max_num;
	}

	int maxPoints(vector<Point> &points) {
		
		int n = points.size();
		int max_num = 0, sub_num = 0;
		
		if(n < 1) return 0;
		if(n == 1) return 1;
		
		vector<Info> max, submax;
		return maxPoints_Detail(points, max, submax, n, max_num, sub_num);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<Point> p;
//	Point data[DATA_SIZE] = {{84,250},{0,0},{1,0},{0,-70},{0,-70},{1,-1},{21,10},{42,90},{-42,-230}};
	Point data[DATA_SIZE] = { {40,-23},{9,138},{429,115},{50,-17},{-3,80},{-10,33},{5,-21},{-3,80},{-6,-65},{-18,26},{-6,-65},{5,72},{0,77},{-9,86},{10,-2},{-8,85},{21,130},{18,-6},{-18,26},{-1,-15},{10,-2},{8,69},{-4,63},{0,3},{-4,40},{-7,84},{-8,7},{30,154},{16,-5},{6,90},{18,-6},{5,77},{-4,77},{7,-13},{-1,-45},{16,-5},{-9,86},{-16,11},{-7,84},{1,76},{3,77},{10,67},{1,-37},{-10,-81},{4,-11},{-20,13},{-10,77},{6,-17},{-27,2},{-10,-81},{10,-1},{-9,1},{-8,43},{2,2},{2,-21},{3,82},{8,-1},{10,-1},{-9,1},{-12,42},{16,-5},{-5,-61},{20,-7},{9,-35},{10,6},{12,106},{5,-21},{-5,82},{6,71},{-15,34},{-10,87},{-14,-12},{12,106},{-5,82},{-46,-45},{-4,63},{16,-5},{4,1},{-3,-53},{0,-17},{9,98},{-18,26},{-9,86},{2,77},{-2,-49},{1,76},{-3,-38},{-8,7},{-17,-37},{5,72},{10,-37},{-4,-57},{-3,-53},{3,74},{-3,-11},{-8,7},{1,88},{-12,42},{1,-37},{2,77},{-6,77},{5,72},{-4,-57},{-18,-33},{-12,42},{-9,86},{2,77},{-8,77},{-3,77},{9,-42},{16,41},{-29,-37},{0,-41},{-21,18},{-27,-34},{0,77},{3,74},{-7,-69},{-21,18},{27,146},{-20,13},{21,130},{-6,-65},{14,-4},{0,3},{9,-5},{6,-29},{-2,73},{-1,-15},{1,76},{-4,77},{6,-29} };
	for(int i = 0; i < DATA_SIZE; i++)
		p.push_back(data[i]);
    int ret = sl.maxPoints(p);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
