class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_num = nums[0];
        for(int &num : nums){
            max_num = max(max_num, num);
        }
        int ans = 0;
        
        int sequence = 0;
        
        for(int &num : nums){
            if(num == max_num) sequence++;
            else sequence = 0;
            ans = max(ans, sequence);
        }
        
        return ans;
    }
};