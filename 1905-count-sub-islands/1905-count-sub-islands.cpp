class Solution {
public:
    void searchIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y, bool &flag){
        int colSize = grid2.size();
        int rowSize = grid2[0].size();
        
        if(x < 0 || y < 0 || x == colSize || y == rowSize || grid2[x][y] == 0) return;
        
        if(grid1[x][y] == 0){
            flag = false;
        }
        grid2[x][y] = 0;
        
        searchIsland(grid1, grid2, x + 1, y, flag);
        searchIsland(grid1, grid2, x, y + 1, flag);
        searchIsland(grid1, grid2, x - 1, y, flag);
        searchIsland(grid1, grid2, x, y - 1, flag);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int colSize = grid1.size();
        int rowSize = grid1[0].size();
        int ans = 0;
        for(int i=0;i<colSize;++i){
            for(int j=0;j<rowSize;++j){
                if(grid2[i][j] == 1){
                    bool flag = true;
                    searchIsland(grid1, grid2, i, j, flag);
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
};