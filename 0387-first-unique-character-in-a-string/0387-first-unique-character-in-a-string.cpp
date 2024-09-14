class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0,};
        int ans = -1;
        for(char ch:s){
            arr[ch-'a']++;
        }
        for(int i=0;i<s.length();++i){
            if(arr[s[i] - 'a'] == 1) return i;
        }
        return ans;
    }
};