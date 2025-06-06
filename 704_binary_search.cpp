#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left <= right){
            int mid = left + ((right - left) / 2);
            cout << "Left: " << left << ", Right: " << right << ", Mid: " << mid << endl;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {-1,0,2,4,6,8};
    int target = 4;

    int result = solution.search(nums, target);
    cout << "Index of target: " << result << endl; // Output should be 4

    return 0;
}