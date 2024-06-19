class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ss = s.length();
        int ts = t.length();
        
        if(ss == 0 && ts == 0) return true;
        if(ts == 0) return false;
        if(ss > ts) return false;
        
        int start_s = 0, start_t = 0;
        while(start_t != ts && start_s != ss){
            if(s[start_s] == t[start_t]) start_s++;
            start_t++;
        }
        
        return (start_s == ss);
    }
};