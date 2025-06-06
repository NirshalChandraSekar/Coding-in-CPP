#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lower = 0;
        int upper = matrix.size() * matrix[0].size();

        while(lower <= upper){
            int mid = lower + ((upper - lower) / 2);
            if(target < matrix[(int)mid/matrix[0].size()][mid % matrix[0].size()]){
                upper = mid - 1;
            }
            else if(target > matrix[(int)mid/matrix[0].size()][mid % matrix[0].size()]){
                lower = mid + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    bool result = solution.searchMatrix(matrix, target);
    cout << "Target found: " << (result ? "Yes" : "No") << endl; // Output should be Yes

    return 0;
}