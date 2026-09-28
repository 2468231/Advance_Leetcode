class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //Dijkfas is the optimal solution for yhis quetion
        // Create matrix
        vector<vector<int>> mat(n, vector<int>(n, 1e9));

        // Distance from a node to itself = 0
        for (int i = 0; i < n; i++) {
            mat[i][i] = 0;
        }

        // Store edges
        for (int i = 0; i < times.size(); i++) {

            int u = times[i][0] - 1;
            int v = times[i][1] - 1;
            int w = times[i][2];

            mat[u][v] = w;
        }

        // Floyd-Warshall
        for (int l = 0; l < n; l++) {

            for (int i = 0; i < n; i++) {

                for (int j = 0; j < n; j++) {

                    mat[i][j] = min(
                        mat[i][j],
                        mat[i][l] + mat[l][j]
                    );
                }
            }
        }

        // k is 1-indexed, convert to 0-index
        k--;

        int ans = 0;

        // Find maximum shortest distance from k
        for (int i = 0; i < n; i++) {

            if (mat[k][i] == 1e9)
                return -1;

            ans = max(ans, mat[k][i]);
        }

        return ans;
    }
};