#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int index = abs(nums[i]);
            if(nums[index] > 0) nums[index] *= -1;
            else return abs(nums[i]);
        }
        return NULL;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {1, 3, 4, 2, 2};

    // Finding the duplicate number
    int duplicate = solution.findDuplicate(nums);

    // Printing the result
    cout << "The duplicate number is: " << duplicate << endl;

    return 0;
}

