class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> st(dictionary.begin(), dictionary.end());
        int slen = s.length();
        int dictlen = dictionary.size();
        vector<int> dp(slen + 1, 0);
        for(int i=1;i<=slen;++i){
            dp[i] = dp[i-1] + 1;
            for(int j=i;j>=1;j--){
                string temp = s.substr(j-1,i-j+1);
                if(st.count(temp)){
                    dp[i] = min(dp[i], dp[j-1]);
                }
            }
        }
        return dp[slen];
    }
};