#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size() - 1;
        while(lower <= upper){
            int mid = lower + ((upper-lower)/2);

            if(target == nums[mid]) return mid;

            if(nums[mid] <= nums[upper]){
                if(target > nums[mid] and target < nums[upper]){
                    lower = mid + 1;
                }
                else{
                    upper = mid - 1;
                }
            }
            else{
                if(target < nums[mid] and target >= nums[lower]){
                    upper = mid - 1;
                }
                else{
                    lower = mid + 1;
                }
            }

            
        }
        return -1;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = solution.search(nums, target);
    cout << "Index of target " << target << ": " << result << endl; // Output: 4
    return 0;
}