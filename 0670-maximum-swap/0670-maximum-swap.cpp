class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int leftidx = -1;
        int rightidx = -1;
        int maxidx = -1;
        int maxval = -1;
        for(int i=s.length() - 1;i>=0;--i){
            if(s[i] > maxval){
                maxval = s[i];
                maxidx = i;
                continue;
            }
            if(s[i] < maxval){
                leftidx = i;
                rightidx = maxidx;
            }
        }
        if(leftidx == -1) return num;
        swap(s[leftidx], s[rightidx]);
        return stoi(s);
    }
};