class Solution {
public:
    string makeFancyString(string s) {
        int size = s.length();
        char prev;
        string ans = "";
        int cnt = 1;
        for(char ch:s){
            if(prev == ch) cnt++;
            else cnt = 1;
            prev = ch;
            if(cnt > 2) continue;
            ans += ch;
        }
        return ans;
    }
};