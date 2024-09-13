class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = arr.size();
        vector<int> ans;
        vector<int> xor_arr(size, 0);
        xor_arr[0] = arr[0];
        for(int i=1;i<size;++i){
            xor_arr[i] = xor_arr[i-1]^arr[i];
        }
        
        for(vector<int> &query : queries){
            int start = query[0];
            int end = query[1];
            if(start == end){
                ans.push_back(arr[start]);
                continue;
            }
            if(start == 0) ans.push_back(xor_arr[end]);
            else ans.push_back(xor_arr[start-1]^xor_arr[end]);
        }
        return ans;
    }
};