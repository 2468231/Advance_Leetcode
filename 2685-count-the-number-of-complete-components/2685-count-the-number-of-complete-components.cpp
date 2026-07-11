class Solution {
public:
    void dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis,
             vector<int>& component)
    {
        vis[node] = 1;
        component.push_back(node);

        for(int nei : adj[node])
        {
            if(!vis[nei])
                dfs(nei, adj, vis, component);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n,0);

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vector<int> component;

                dfs(i, adj, vis, component);

                int k = component.size();

                bool complete = true;

                for(int node : component)
                {
                    if(adj[node].size() != k-1)
                    {
                        complete = false;
                        break;
                    }
                }

                if(complete)
                    ans++;
            }
        }

        return ans;
    }
};