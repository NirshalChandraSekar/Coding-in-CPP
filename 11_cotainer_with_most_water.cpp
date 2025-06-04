#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int max_area = 0;
        while(left<right){
            int area = (right - left) * (min(heights[left], heights[right]));
            
            if(area > max_area){
                max_area = area;
            }
            
            if(heights[right] > heights[left]){
                left++;
            }
            else if(heights[left] > heights[right]){
                right--;
            }
            else{
                right--;
            }
            

        }
        return max_area;
    }
};

int main() {
    Solution solution;
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    int result = solution.maxArea(heights);
    cout << "Maximum area of water container: " << result << endl; // Output: 49
    return 0;
}