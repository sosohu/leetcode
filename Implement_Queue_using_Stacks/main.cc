#include <iostream>
#include <stack>

using namespace std;


class Queue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        if(stack2.empty())  stack2.push(x);
        else     stack1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        int ele = stack2.top();
        stack2.pop();
        if(stack2.empty())
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        return stack2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stack2.empty();
    }
};

int main(int argc, char** argv)
{

	return 0;
}
