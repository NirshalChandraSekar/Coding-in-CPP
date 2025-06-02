#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> table;
    vector<int> output;

    // Create the hash table
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(int i : nums){
            if(table.count(i) > 0){
                table[i] += 1;
            }
            else{
                table[i] = 1;
            }
        }

    // Vector with frequency-key pair
    vector<pair<int,int>> arr;
    for(auto i : table){
        arr.push_back({i.second, i.first});
    }
    sort(arr.rbegin(), arr.rend());

    //return the first k elements

    
    for(auto i=0; i<k; i++){
        output.push_back(arr[i].second);
    }
    return output;
    }
}; 

int main() {
    Solution obj;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = obj.topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent elements: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
