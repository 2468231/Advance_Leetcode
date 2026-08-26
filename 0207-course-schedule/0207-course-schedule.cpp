class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& CyVis) {

        vis[node] = 1;
        CyVis[node] = 1;

        for (int next : adj[node]) {

            // Node has not been visited
            if (!vis[next]) {

                if (dfs(next, adj, vis, CyVis))
                    return true;
            }

            // Node is already in current DFS path
            else if (CyVis[next]) {
                return true;
            }
        }

        // Remove from current DFS path
        CyVis[node] = 0;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prer) {

        // Create adjacency list
        vector<vector<int>> adj(numCourses);

        // Build graph
        for (int i = 0; i < prer.size(); i++) {
            adj[prer[i][1]].push_back(prer[i][0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> CyVis(numCourses, 0);

        // Check every course
        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {

                if (dfs(i, adj, vis, CyVis))
                    return false;
            }
        }

        return true;
    }
};