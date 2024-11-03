class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s == goal) return true;
        int size = s.length();
        int len = s.length();
        string str = s;
        while(--size){
            str = str.substr(1, len) + str[0];
            if(str == goal) return true;
        }
        return false;
    }
};