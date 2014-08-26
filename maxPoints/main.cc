#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//#define DATA_SIZE 9
#define DATA_SIZE 4

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
			int   count;
			
			Info(){}

			Info(Point one, int count) : one(one) , count(count) {
			}

			void set(Point one_arg, int count_arg){
				one = one_arg;
				count = count_arg;
			}
			
		} ;	

		struct KInfo{
			double k;
			int count;
			KInfo() {}
			
			void set(double k_arg, int count_arg){
				k = k_arg;
				count = count_arg;
			}
		};

	struct PointCompare {
		bool operator() (Point i,Point j) { 
				if(i.x < j.x) return true;
				if(i.x == j.x && i.y <= i.y) return true;
				return false;
		}
	} pointcompare;

	struct InfoCompare {
		bool operator() (Info i,Info j) { 
			return i.count < j.count;
		}
	} infocompare;

	struct KCompare {
		bool operator() (KInfo i,KInfo j) { 
			return i.k < j.k;
		}
	} kcompare;

public:
	int maxPoints_Detail(vector<Point> &points, vector<int>& count, int n){
		if(n == 2) return count[0] + count[1];
		int com = maxPoints_Detail(points, count, n-1);
		vector<KInfo> k_vec;
		int is_y_count = 0;
		KInfo kinfo;
		for(int i = 0; i < n -1 ; i++){
			if(points[i].x != points[n-1].x){
				kinfo.set((points[i].y - points[n-1].y)*1.0
								/(points[i].x - points[n-1].x), count[i]);
				k_vec.push_back(kinfo);
			}
			else{
				is_y_count = is_y_count + count[i];
			}
		}
		int contain = 0;
		int max_count = 0;
		cout<<"+++++++++++++"<<endl;
		if(!k_vec.empty()){
			std::sort(k_vec.begin(), k_vec.end(), kcompare);
			max_count = k_vec[0].count;
			int cur_count = k_vec[0].count;
			double last_k = k_vec[0].k;
			cout<<last_k<<endl;
			for(int i = 1; i < k_vec.size(); i++){
				cout<<k_vec[i].k<<endl;
				if(last_k == k_vec[i].k)
				   cur_count = cur_count + k_vec[i].count;
				else{
					if(cur_count > max_count)
						max_count = cur_count;
					cur_count = k_vec[i].count;
					last_k = k_vec[i].k;
				}	
			}
			if(cur_count > max_count) max_count = cur_count;
		}
		cout<<"***************"<<endl;
		contain = max_count > is_y_count? max_count : is_y_count;
		contain = contain + count[n-1];
		int num = contain > com? contain : com;
		return num;
	}


	void preProcess(vector<Point> &points, vector<int>& count){
		int size = points.size();
		if(size <= 1) return;
		std::sort(points.begin(), points.end(), pointcompare);
		Point last = points[0];
		vector<Point> temp;
		temp.push_back(last);
		int j = 0;
		count.push_back(1);
		for(int i = 1; i < size; i++){
			if(last.x == points[i].x && last.y == points[i].y)
				count[j]++;
			else{
				last = points[i];
				temp.push_back(last);
				count.push_back(1);
				j++;
			}
		}
		points.swap(temp);
		vector<Info> info_vec;
		Info info;
		for(int i = 0; i < points.size(); i++){
				info.set(points[i], count[i]);
				info_vec.push_back(info);
		}
		std::sort(info_vec.begin(), info_vec.end(), infocompare);
		for(int i = 0; i < points.size(); i++){
			points[i] = info_vec[i].one;
			count[i] = info_vec[i].count;
		}
	}

	int maxPoints(vector<Point> &points) {
		int n = points.size();
		if(n < 1) return 0;
		if(n == 1) return 1;

		vector<int> count;
		preProcess(points, count);

		n = points.size();

		if(n == 1) return count[0];
		
		return maxPoints_Detail(points, count, n);
    }

};

int main(int argc, char** argv)
{
	Solution sl;
	vector<Point> p;
	Point data[DATA_SIZE] = {{-4,1},{-7,7},{-1,5},{9,-25}};
//	Point data[DATA_SIZE] = {{84,250},{0,0},{1,0},{0,-70},{0,-70},{1,-1},{21,10},{42,90},{-42,-230}};
//	Point data[DATA_SIZE] = { {40,-23},{9,138},{429,115},{50,-17},{-3,80},{-10,33},{5,-21},{-3,80},{-6,-65},{-18,26},{-6,-65},{5,72},{0,77},{-9,86},{10,-2},{-8,85},{21,130},{18,-6},{-18,26},{-1,-15},{10,-2},{8,69},{-4,63},{0,3},{-4,40},{-7,84},{-8,7},{30,154},{16,-5},{6,90},{18,-6},{5,77},{-4,77},{7,-13},{-1,-45},{16,-5},{-9,86},{-16,11},{-7,84},{1,76},{3,77},{10,67},{1,-37},{-10,-81},{4,-11},{-20,13},{-10,77},{6,-17},{-27,2},{-10,-81},{10,-1},{-9,1},{-8,43},{2,2},{2,-21},{3,82},{8,-1},{10,-1},{-9,1},{-12,42},{16,-5},{-5,-61},{20,-7},{9,-35},{10,6},{12,106},{5,-21},{-5,82},{6,71},{-15,34},{-10,87},{-14,-12},{12,106},{-5,82},{-46,-45},{-4,63},{16,-5},{4,1},{-3,-53},{0,-17},{9,98},{-18,26},{-9,86},{2,77},{-2,-49},{1,76},{-3,-38},{-8,7},{-17,-37},{5,72},{10,-37},{-4,-57},{-3,-53},{3,74},{-3,-11},{-8,7},{1,88},{-12,42},{1,-37},{2,77},{-6,77},{5,72},{-4,-57},{-18,-33},{-12,42},{-9,86},{2,77},{-8,77},{-3,77},{9,-42},{16,41},{-29,-37},{0,-41},{-21,18},{-27,-34},{0,77},{3,74},{-7,-69},{-21,18},{27,146},{-20,13},{21,130},{-6,-65},{14,-4},{0,3},{9,-5},{6,-29},{-2,73},{-1,-15},{1,76},{-4,77},{6,-29} };
	for(int i = 0; i < DATA_SIZE; i++)
		p.push_back(data[i]);
    int ret = sl.maxPoints(p);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
