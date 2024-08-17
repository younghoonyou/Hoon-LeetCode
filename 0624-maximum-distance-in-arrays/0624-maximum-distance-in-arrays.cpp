class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int distance = 0;
        int small = arrays[0][0];
        int big = arrays[0].back();
        
        for(int i=1;i<arrays.size();++i){
            distance = max(distance, arrays[i].back() - small);
            distance = max(distance, big - arrays[i][0]);
            
            small = min(small, arrays[i][0]);
            big = max(big, arrays[i].back());
        }
        return distance;
    }
};