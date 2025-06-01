#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> table;
    vector<vector<string>> output;

    void hashtable(string key, string value){
        if(table.count(key) > 0){
            table[key].push_back(value);
        }
        else{
            table[key] = {value};
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        for(string i : strs){
            string key = i;
            sort(key.begin(), key.end());
            hashtable(key, i);
        }

        for(auto key : table){
            output.push_back(key.second);
        }

        return output;
        
        
    }
};

int main() {
    Solution obj;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = obj.groupAnagrams(strs);
    
    cout << "Grouped anagrams:" << endl;
    for(const auto& group : result) {
        for(const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}