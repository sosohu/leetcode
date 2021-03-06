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
		if(track.empty() || x <= track.top())
			track.push(x);
    }

    void pop(){
		if(data.top() == track.top())
			track.pop();
		data.pop();
    }

    int top(){
		return data.top();
    }

    int getMin(){
		return track.top();
    }

private:
	stack<int> data;
	stack<int> track;
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
