class Solution {
public:
    void DFS(vector<int>& nums,int idx,int temp, int maxNum, int &cnt){
        if(idx == nums.size()){
            if(maxNum == temp) cnt++;
            return;
        }
        DFS(nums,idx+1,temp, maxNum, cnt);
        DFS(nums,idx+1,temp|nums[idx], maxNum, cnt);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxNum = 0;
        for(int &num : nums) maxNum |= num;
        int cnt = 0;
        DFS(nums,0, 0,maxNum, cnt);
        return cnt;
    }
};