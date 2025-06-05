#include <stack>
#include <iostream>
using namespace std;

class MinStack {
public:
    stack<int> mystack;
    stack<int> min_stack;
    MinStack() {
    }
    
    void push(int val) {
        mystack.push(val);
        if(min_stack.size() == 0)  min_stack.push(val); 
        else  min_stack.push(min(min_stack.top(), val)); 
    }
    
    void pop() {
        mystack.pop();
        min_stack.pop();
    }
    
    int top() {
        return mystack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};


int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum: " << minStack.getMin() << endl; // Returns -3.
    minStack.pop();
    cout << "Top: " << minStack.top() << endl; // Returns 0.
    cout << "Minimum: " << minStack.getMin() << endl; // Returns -2.
    return 0;
}