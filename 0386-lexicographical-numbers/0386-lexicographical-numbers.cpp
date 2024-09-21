class Solution {
public:
    int numberLength(int num){
        int len = 0;
        while(num){
            num/=10;
            len++;
        }
        return len;
    }
    
    void helperLexicographical(vector<int> &ans, int start, int n){
        if(n < start) return;
        ans.push_back(start);
        for(int i=0;i<=9;++i){
            helperLexicographical(ans, start*10 + i, n);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        int len = numberLength(n);
        vector<int> ans;
        for(int i=1;i<=9;++i){
            if(i > n) continue;
            helperLexicographical(ans, i, n);
        }
        return ans;
    }
};