class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        int INF = 100000000;
        
        // 2D distance matrix
        vector<vector<int>> mat(n, vector<int>(n, INF));

        // Distance from a city to itself = 0
        for(int i = 0; i < n; i++) {
            mat[i][i] = 0;
        }

        // Add the edges
        for(const vector<int>& it : edges) {
            int i = it[0];
            int j = it[1];
            int w = it[2];

            mat[i][j] = w;
            mat[j][i] = w;
        }

        // Floyd-Warshall
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    mat[i][j] = min(mat[i][j], 
                                    mat[i][k] + mat[k][j]);
                }
            }
        }

        // Find city with minimum reachable cities
        // If tie, choose greatest city index
        int ans = -1;
        int minCount = INF;

        for(int i = 0; i < n; i++) {
            int count = 0;

            for(int j = 0; j < n; j++) {
                if(mat[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            if(count <= minCount) {
                minCount = count;
                ans = i;
            }
        }

        return ans;
    }
};
