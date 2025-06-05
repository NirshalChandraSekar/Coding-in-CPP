#include <stack>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mystack;
        for(auto i : tokens){
            if(i!="+" && i!="-" && i!="*" && i!="/"){
                mystack.push(stoi(i));
            }
            else{
                int first = mystack.top(); mystack.pop();
                int second = mystack.top(); mystack.pop();
                if(i == "+") mystack.push(first + second);
                else if(i == "-") mystack.push(first - second);
                else if(i == "*") mystack.push(first * second);
                else if(i == "/") mystack.push(first / second);
            }
        }
        return mystack.top();  
    }
};


int main() {
    Solution solution;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << "Result: " << solution.evalRPN(tokens) << endl; // Output should be 9
    return 0;
}