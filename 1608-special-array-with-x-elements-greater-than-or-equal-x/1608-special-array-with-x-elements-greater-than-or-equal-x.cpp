class Solution {
public:
    int specialArray(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int ret = 0;
        while(ret <= size){
            int cmp = 0;
            for(int idx = 0;idx<size;idx++){
                if(nums[idx] >= ret) cmp++;
            }
            if(cmp == ret) return ret;
            ret++;
        }
        return -1;
    }
};