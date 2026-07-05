class Solution {
public:
    void dfs(int t, int k, vector<vector<char>>& grid, int n,int m){
        grid[t][k] = '2';
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0,  1, 0, -1};
         for(int l=0; l<4; l++){
            int curRow = t + drow[l];
            int curCol = k + dcol[l];
            if(curRow >= 0 && curCol >= 0 && curRow < n && curCol < m && grid[curRow][curCol] == '1'){
            dfs(curRow, curCol, grid, n, m);
            }
         }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i, j, grid, n, m);
                }
            }
        }
        return count;
    }
};