#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 1;
        int right = numbers.size();
        while(left < right){
            if( (numbers[left-1]+numbers[right-1]) == target){
                return {left, right};
            }
            else if((numbers[left-1]+numbers[right-1]) < target){
                left ++;
            }
            else{
                right --;
            }

        }
        return {}; 
    }
};

int main() {
    Solution solution;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(numbers, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl; // Output: Indices: 1, 2
    return 0;
}