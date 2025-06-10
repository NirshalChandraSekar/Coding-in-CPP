#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,4,5,1,2};

    int result = solution.findMin(nums);
    cout << "Minimum in rotated sorted array: " << result << endl; // Output should be 1

    return 0;
}