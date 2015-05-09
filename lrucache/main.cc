/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-05-09 14:53
 * Filename :        main.cc
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

#define DATASIZE 6


class LRUCache {
private:
	struct ListNode{
		int key;
		int value;
		ListNode *pre, *next;
		ListNode(int key = -1, int value = -1) : key(key), value(value), pre(NULL), next(NULL)
		{} 
	};

	unordered_map<int, ListNode*> table;
	ListNode seq_head;
	ListNode seq_end;
	int capacity;
	int size;

private:
	void seq_push_back(ListNode *pos){
		seq_end.pre->next = pos;
		pos->pre = seq_end.pre;
		seq_end.pre = pos;
		pos->next = &seq_end;
	}

	void seq_erase(ListNode *pos){
		pos->pre->next = pos->next;
		pos->next->pre = pos->pre;
	}

public:

	LRUCache(int capacity) : capacity(capacity){
		size = 0;
		seq_head.next = &seq_end;
		seq_end.pre = &seq_head;
	}

	int get(int key){
		if(table.count(key) == 0)	return -1;
		seq_erase(table[key]);
		seq_push_back(table[key]);
		return table[key]->value;
	}


	void set(int key, int value){
		if(table.count(key)){
			table[key]->value = value;
			seq_erase(table[key]);
			seq_push_back(table[key]);
		}else{ 
			if(size >= capacity){
				ListNode *old = seq_head.next;
				table.erase(old->key);
				seq_erase(old);
				delete old;
				size--;
			}
			size++;
			table[key] = new ListNode(key, value);
			seq_push_back(table[key]);
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
