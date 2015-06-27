#include <iostream>

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if(!empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop(void) {
        q1.pop();
        while(q2.size() > 1){
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1, q2);
    }

    // Get the top element.
    int top(void) {
        return q1.front();
    }

    // Return whether the stack is empty.
    bool empty(void) {
        return q1.empty();
    }

private:
    queue<int> q1, q2;
    int index;
};
