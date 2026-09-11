class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // Start or destination blocked
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        // 8 directions
        int Direct8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int Direct2[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        // {row, col, distance}
        queue<pair<pair<int,int>, int>> q;

        q.push({{0, 0}, 1});

        // Mark visited
        grid[0][0] = 1;

        while(!q.empty()) {

            auto curr = q.front();
            q.pop();

            int row = curr.first.first;
            int col = curr.first.second;
            int dist = curr.second;

            // Destination reached
            if(row == n-1 && col == n-1)
                return dist;

            // Check all 8 directions
            for(int i = 0; i < 8; i++) {

                int nr = row + Direct8[i];
                int nc = col + Direct2[i];

                // Check valid cell
                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < n &&
                   grid[nr][nc] == 0) {

                    grid[nr][nc] = 1;

                    q.push({{nr, nc}, dist + 1});
                }
            }
        }

        return -1;
    }
};