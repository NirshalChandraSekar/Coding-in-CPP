#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        unordered_map<int,int> hashmap;
        for(int i=0; i<nums.size(); i++){
            if(hashmap.count(target-nums[i]) >0){
                return {hashmap[target-nums[i]], i};
            }
            else{
                hashmap[nums[i]] = i;
            }
        }
        return{};
    }
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
