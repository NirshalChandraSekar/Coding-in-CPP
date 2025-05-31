#include<iostream>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;

    }
};

int main(){
    Solution obj;
    vector<int> check = {1,1,2,3,4};
    cout << obj.hasDuplicate(check);
    return 0;
}

