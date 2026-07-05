class Solution {
public:
    void dfs(int row, int col, int &count, bool &touchesBoundary,
             vector<vector<int>> &grid, int n, int m) {

        grid[row][col] = 2;      // Mark as visited
        count++;                 // Count this land cell

        // Check if current cell is on the boundary
        if (row == 0 || col == 0 || row == n - 1 || col == m - 1)
            touchesBoundary = true;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = row + drow[i];
            int nc = col + dcol[i];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                grid[nr][nc] == 1) {

                dfs(nr, nc, count, touchesBoundary, grid, n, m);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {

                    int count = 0;
                    bool touchesBoundary = false;

                    dfs(i, j, count, touchesBoundary, grid, n, m);

                    if (touchesBoundary == false){
                        ans += count;
                    }
                }
            }
        }

        return ans;
    }
};