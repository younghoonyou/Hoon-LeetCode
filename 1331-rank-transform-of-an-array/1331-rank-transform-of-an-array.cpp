class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int rank = 1;
        vector<int> ans;
        set<int> st(arr.begin(), arr.end());
        unordered_map<int,int> m;
        for(int num : st) m[num] = rank++;
        for(int num:arr) ans.push_back(m[num]);
        return ans;
    }
};