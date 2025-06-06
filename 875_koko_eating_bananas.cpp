#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lower = 1;
        int upper = *max_element(piles.begin(), piles.end());
        int min_k = upper;

        while(lower <= upper){
            int hours = 0;
            int mid = lower + ((upper - lower)/2);
            for(int i = 0; i < piles.size(); i++){
                hours += (piles[i] + mid - 1) / mid;
            }
            if(hours <= h){
                min_k = mid;
                upper = mid - 1;
            }
            else{
                lower = mid + 1;
            }
        }
        return min_k;
    }
};


int main() {
    Solution solution;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int result = solution.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl; // Output should be 4

    return 0;
}