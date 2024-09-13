class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(vector<int> &query : queries){
            int start = query[0];
            int end = query[1];
            if(start == end){
                ans.push_back(arr[start]);
                    continue;
            }
            int ret = 0;
            while(start <= end){
                if(start != end) ret ^= arr[start];
                ret ^= arr[end];
                start++, end--;
            }
            
            ans.push_back(ret);
        }
        return ans;
    }
};