class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool alpha[26] = {false, };
        int ans = words.size();
        for(char &ch : allowed) alpha[ch - 'a'] = true;
        for(string &word : words){
            for(char &ch : word){
                if(!alpha[ch - 'a']){
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};