class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        std::map<int, std::map<int, int>> m;
        int ans = 0;
        for(vector<int> &domino:dominoes){
            if(domino[1] <= domino[0]) m[domino[1]][domino[0]]++;
            else m[domino[0]][domino[1]]++;
        }
        for(auto it:m){
            for(auto its:it.second){
                if(its.second != 1){
                    ans += (its.second * (its.second - 1)) / 2;
                }
            }
        }
        return ans;
    }
};