class Solution {
public:
    void helperLexicographical(vector<int> &ans, int start, int n){
        if(n < start) return;
        ans.push_back(start);
        for(int i=0;i<=9;++i){
            helperLexicographical(ans, start*10 + i, n);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=9;++i){
            if(i > n) continue;
            helperLexicographical(ans, i, n);
        }
        return ans;
    }
};