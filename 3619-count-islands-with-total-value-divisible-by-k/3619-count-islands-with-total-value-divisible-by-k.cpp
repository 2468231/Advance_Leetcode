
class Solution {
public:
    int n, m;

    void fun(int i, int j, long long &sum,
             vector<vector<int>>& grid,
             vector<vector<int>>& vis) {

        vis[i][j] = 1;
        sum += grid[i][j];

        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};

        for (int l = 0; l < 4; l++) {
            int ni = i + di[l];
            int nj = j + dj[l];

            if (ni >= 0 && ni < n &&
                nj >= 0 && nj < m &&
                grid[ni][nj] > 0 &&
                !vis[ni][nj]) {
                fun(ni, nj, sum, grid, vis);
            }
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
       n = grid.size();
       m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
     
        int count = 0;
        for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
            if(grid[i][j] > 0 && !vis[i][j]){
                long long sum = 0;
                fun(i, j, sum, grid, vis);
                if(sum % k == 0){
                    count++;
                }
            }
         }
        }
        return count;
    }
};