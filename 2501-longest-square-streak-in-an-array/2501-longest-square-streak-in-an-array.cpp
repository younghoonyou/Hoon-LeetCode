class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<long long, int> m;
        for(int &num:nums) m[num]++;
        int mx = -1;
        bool flag = false;
        for(auto it:m){
            long long num = it.first*it.first;
            int cnt = 1;
            while(m.count(num) == 1){
                cnt++;
                num = num*num;
                flag = true;
            }
            mx = max(mx, cnt);
        }
        
        if(!flag) return -1;
        
        return mx;
    }
};