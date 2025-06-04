#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        unordered_map<char, char> table = {{')', '('},
                                           {']', '['},
                                           {'}', '{'}};
        
        for(auto x : s){
            if(table.count(x) == 0){
                mystack.push(x);
            }
            else{
                if(mystack.size() == 0 || mystack.top() != table[x]){
                    return false;
                }
                mystack.pop();
            }
        }
        return mystack.size() == 0;
    }
};

int main() {
    Solution solution;
    string test1 = "()[]{}";
    cout << (solution.isValid(test1) ? "True" : "False") << endl; // Output: True
    
    string test2 = "(]";
    cout << (solution.isValid(test2) ? "True" : "False") << endl; // Output: False
    
    string test3 = "([)]";
    cout << (solution.isValid(test3) ? "True" : "False") << endl; // Output: False
    
    string test4 = "{[]}";
    cout << (solution.isValid(test4) ? "True" : "False") << endl; // Output: True
    
    return 0;
}