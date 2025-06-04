#include <vector>
#include <string>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        for(int a=0; a<nums.size()-2; a++){
            if(a>0 && nums[a] == nums[a-1]){
                continue;
            }
            int i = a+1;
            int j = nums.size()-1;
            while(i<j){
                if(nums[a]+nums[i]+nums[j] == 0){
                    output.push_back({nums[a], nums[i], nums[j]});
                    i++;
                    j--;
                    while(i<j && nums[i] == nums[i-1]){
                        i++;
                    }
                    while(i<j && nums[j] == nums[j+1]){
                        j--;
                    }
                }
                else if(nums[a]+nums[i]+nums[j] > 0){
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return output;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = solution.threeSum(nums);
    
    cout << "Triplets that sum to zero:" << endl;
    for (const auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    
    return 0;
}