#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> output;
            for(int i=0; i<nums.size()-1; i++){
                for(int j=i+1; j<nums.size(); j++){
                    if( (nums[i]+nums[j]) == target){
                        output.push_back(i);
                        output.push_back(j);
                        return output;
                    }
                }
            }
            return output;
    };
};

int main() {
    Solution obj;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = obj.twoSum(nums, target);
    
    cout << "Indices of the two numbers that add up to " << target << ": ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
