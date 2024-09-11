class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num = start^goal;
        int ret = 0;
        while(num){
            if(num & 1) ret++;
            num >>=1;
        }
        return ret;
    }
};