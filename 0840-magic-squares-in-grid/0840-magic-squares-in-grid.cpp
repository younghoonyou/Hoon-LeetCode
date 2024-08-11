class Solution {
public:
    
    int DFS(int x, int y, vector<vector<int>>& grid){
        int bit = 1;
        int rowSum = grid[x][y] + grid[x][y + 1] + grid[x][y + 2];
        int colSum = grid[x][y] + grid[x + 1][y] + grid[x + 2][y];
        int diagonalSum = grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2];
        int revdiagonalSum = grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y];
        if(diagonalSum != revdiagonalSum) return 0;
        
        for(int i=0;i<3;++i){
            int row_sum = 0;
            int col_sum = 0;
            int diagonal_sum = 0;
            for(int j = 0;j<3;++j){
                row_sum += grid[x + i][y + j];
                col_sum += grid[x + j][y + i];
                bit ^= grid[x + i][y + j];
            }
            if(row_sum != rowSum || col_sum != colSum) return 0;
        }
        
        return bit ? 0 : 1;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int rowSize = grid.size();
        int colSize = grid[0].size();
        if(colSize < 3 || rowSize < 3) return 0;
        
        int ret = 0;
        
        for(int i = 0 ; i <= colSize - 3 ; i++){
            for(int j = 0 ; j <= rowSize - 3 ; j++){
                 ret += DFS(j,i,grid);
            }
        }
        
        return ret;
    }
};