class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum = 0;
        for(int &x : chalk){
            sum += x;
        }
        int remain = k % sum;
        int idx = 0;
        while(remain != 0){
            if(remain < 0){
                return idx - 1;
            }
            remain -= chalk[idx];
            idx++;
        }
        return idx;
    }
};