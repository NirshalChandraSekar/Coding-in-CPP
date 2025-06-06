#include <vector>
#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> combined;
        vector<double> stack;

        for(int i=0; i<position.size(); i++){
            combined.push_back({position[i], speed[i]});
        }
        sort(combined.rbegin(), combined.rend());

        for(auto data : combined){
            auto pos = data.first;
            auto speed = data.second;
            
            stack.push_back((double)(target - pos) / speed);
            if(stack.size()>=2 && stack[stack.size()-1] <= stack[stack.size()-2]){
                stack.pop_back();
            }  
        }
        return stack.size();       
    }
};

int main() {
    Solution solution;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    int target = 12;

    int result = solution.carFleet(target, position, speed);
    cout << "Number of car fleets: " << result << endl; // Output should be 3

    return 0;
}