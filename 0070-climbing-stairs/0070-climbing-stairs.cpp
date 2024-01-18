class Solution {
public:
    int steps[46] = {0,};
    int climbStairs(int n) {
        if(steps[n]) return steps[n];
        
        if(n == 1){
            steps[n] = 1;
        }
        else if(n == 2){
            steps[n] = 2;
        }
        else{
            steps[n] = climbStairs(n-2) + climbStairs(n-1);
        }
        return steps[n];
    }
};