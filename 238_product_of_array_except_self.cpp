#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int left = 1;
        for(int i=0; i<nums.size(); i++){
            output.push_back(left);
            left *= nums[i];
        }

        int right = 1;
        for(int i=nums.size()-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = obj.productExceptSelf(nums);
    
    cout << "Product of array except self: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}


