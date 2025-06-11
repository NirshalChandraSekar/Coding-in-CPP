#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> dict;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if(dict.count(key) == 0){
            dict.insert({key, {{value, timestamp}}});
        }
        else{
            dict[key].push_back({value, timestamp});
        }
    }
    string get(string key, int timestamp) {
        if(dict.count(key) == 0) return "";

        int lower = 0;
        int upper = dict[key].size() - 1;

        while(lower <= upper){
            int mid = lower + ((upper-lower)/2);
            
            if(timestamp == dict[key][mid].second) return dict[key][mid].first;

            else if(timestamp < dict[key][mid].second) upper = mid-1;

            else lower = mid + 1;
        }
        if(upper >= 0) return dict[key][upper].first;

        return "";
        
    }
};


int main() {
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    cout << timeMap.get("foo", 1) << endl; // Output: "bar"
    cout << timeMap.get("foo", 3) << endl; // Output: "bar"
    timeMap.set("foo", "bar2", 4);
    cout << timeMap.get("foo", 4) << endl; // Output: "bar2"
    cout << timeMap.get("foo", 5) << endl; // Output: "bar2"
    return 0;
}
