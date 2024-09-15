class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> vowles = {
            {'a', 0},
            {'e', 1},
            {'i', 2},
            {'o', 3},
            {'u', 4},
        };
        unordered_map<int, int> keep;
        keep[0] = -1;
        int ans = 0;
        int cur = 0;
        for(int i = 0;i<s.size();++i){
            if(vowles.find(s[i])!=vowles.end()){
                cur ^= (1 << vowles[s[i]]);
            }
            if(keep.find(cur)!=keep.end()){
                ans = max(ans, i - keep[cur]);
            }
            else{
                keep[cur] = i;
            }
        }
        return ans;
    }
};