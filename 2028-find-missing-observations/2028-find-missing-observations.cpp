class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int size = rolls.size();
        int total = 0;
        for(int &roll : rolls){
            total += roll;
        }
        total = mean * (size + n) - total;
        if(total > n * 6 || total < n) return {};
        int dist = total / n, remaining = total % n;
        vector<int> ret(n, dist);
        
        while(remaining--){
            ret[remaining%n]++;
        }
        
        return ret;
    }
};