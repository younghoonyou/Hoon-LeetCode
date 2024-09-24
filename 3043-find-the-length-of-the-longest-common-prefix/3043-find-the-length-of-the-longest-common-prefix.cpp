class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> st;
        for(int &num:arr1){
            string num_string = to_string(num);
            string prefix;
            for(char &ch:num_string){
                prefix += ch;
                st.insert(prefix);
            }
        }
        int ans = 0;
        for(int &num:arr2){
            string num_string = to_string(num);
            string prefix;
            for(char &ch:num_string){
                prefix += ch;
                if(st.count(prefix)){
                    int size = prefix.length();
                    ans = max(ans, size);
                }
            }
        }
        return ans;
    }
};