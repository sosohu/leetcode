/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2014-11-14 12:37
 * Filename :        main.cc
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/

#include <iostream>
#include <string>
#include <stack>

using namespace std;


class MinStack {

public:

	void push(int x) {
		data.push(x);
		if(!min.empty()){
			if(x <= min.top()){
				min.push(x);
			}	
		}else{
			min.push(x);
		}
    }

    void pop(){
		int ret = data.top();
		data.pop();
		if(ret == min.top()){
			min.pop();
		}
    }

    int top(){
		return data.top();
    }

    int getMin(){
		return min.top();
    }

private:
	stack<int> data;
	stack<int> min;
};

int main(int argc, char** argv)
{
	MinStack ms;
	ms.push(-1);
	ms.push(-2);
	ms.push(0);
	ms.push(-1);
	ms.push(-2);
	ms.push(0);
	cout<<ms.getMin()<<endl;
	ms.pop();
	cout<<ms.getMin()<<endl;
	ms.pop();
	cout<<ms.getMin()<<endl;

	return 0;

}
