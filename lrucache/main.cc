#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define DATASIZE 6


class LRUCache {
private:
	typedef std::pair<int,int> Value_CountID;    // value, count_id
	std::map<int, Value_CountID> data;	 // key, vale cound_id
	typedef std::pair<long int,int> Time_Key;    // count, time
	std::vector<Time_Key> count;     // count , key
	int capacity;
	int size;
	long time_max;

private:
	int min_countID(int s, int e, int n){
		if(n == 1) return s;
		int part = s + n / 2;
		int up = min_countID(part , e , n - n/2 );
		int down = min_countID(s, part - 1, n/2);
		int min;
		min = count[up].first < count[down].first? up:down;
		return min;
	}

	int getLRU(){
		int min_count_id = min_countID(0, size -1 , size);
		return count[min_count_id].second;
	}

public:

	LRUCache(int capacity){
		this->capacity = capacity;
		size = 0;
		time_max = 0;
	}

	int get(int key){
		if(data.count(key) == 1){
			time_max++;
			count[data[key].second].first = time_max;
			return data[key].first;
		}else{
			return -1;
		}
	}

	void print(){
		for(std::vector<Time_Key>::iterator iter = count.begin();
			iter != count.end(); iter++	
			){
			cout<<"	time: "<<iter->first;
			cout<<"	key: "<<iter->second<<endl;
		}
	}


	void set(int key, int value){
		time_max++;
		if(data.count(key) == 1){
		// exist in the map
			data[key].first = value;
			count[data[key].second].first = time_max;
		}
		else{
			if(size < capacity){
				data[key].first = value;
				data[key].second = size;
				Time_Key count_time(time_max,key);
				count.push_back(count_time);
				size++;
			}
			else{
				int replace = getLRU();  // return the key
				int count_id = data[replace].second;
				count[count_id].first = time_max;
				count[count_id].second = key;
				data.erase(replace);
				data[key].first = value;
				data[key].second = count_id;
			}
		}
	}

};

int main(int argc, char** argv)
{
	LRUCache lc(3);
	int data[DATASIZE][2] = {{1,2},{2,2},{3,3},{2,3},{4,5},{5,6}};	

	for(int i = 0; i < DATASIZE; i++){
		lc.set(data[i][0],data[i][1]);
		cout<<"Input  :Key "<<data[i][0]<<" Value "<<data[i][1]<<endl;
	}
	for(int i = 0; i < DATASIZE; i++){
		cout<<"Result  :Key "<<data[i][0]<<" Value "<<lc.get(data[i][0])<<endl;
	}
	

	return 0;

}
