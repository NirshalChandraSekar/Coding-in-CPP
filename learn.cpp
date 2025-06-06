#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;


int main(){
    
    vector<int> nums = {1, 2, 3, 4, 5};
    
    cout << *max_element(nums.begin(), nums.end());
}

