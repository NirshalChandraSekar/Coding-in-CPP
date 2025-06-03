#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string new_ = "";
        for(char str : s){
            if(isalnum(str)){
                new_ += tolower(str);
            }
        }
        return new_ == string(new_.rbegin(), new_.rend());
    }
};

int main() {
    Solution solution;
    string test1 = "deified";
    solution.isPalindrome(test1) ? cout << "True" : cout << "False";
    cout << endl;
    return 0;
}
