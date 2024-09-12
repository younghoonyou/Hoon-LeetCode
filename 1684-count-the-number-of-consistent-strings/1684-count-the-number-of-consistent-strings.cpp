class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, bool> m;
        int ans = 0;
        for(char &ch : allowed) m[ch] = true;
        for(string &word : words){
            bool included = true;
            for(char &ch : word){
                if(m.find(ch)==m.end()){
                    included = false;
                    break;
                }
            }
            if(included) ans++;
        }
        return ans;
    }
};