#include <cmath>
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::map<int,int> m;
        for(int &x : arr){
            m[x]++;
        }
        vector<bool> bool_arr(1000, false);
        for(auto i:m){
            int check = i.second;
            if(bool_arr[check]){
                return false;
            }
            bool_arr[check] = true;
        }
        return true;
    }
};