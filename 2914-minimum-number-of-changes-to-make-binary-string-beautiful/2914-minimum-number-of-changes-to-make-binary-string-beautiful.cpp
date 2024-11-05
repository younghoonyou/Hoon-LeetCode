class Solution {
public:
    int minChanges(string s) {
        int size = s.length();
        int cnt = 0;
        for(int i=0;i<size - 1;i+=2){
            if(s[i] != s[i+1]) cnt++;
        }
        return cnt;
    }
};