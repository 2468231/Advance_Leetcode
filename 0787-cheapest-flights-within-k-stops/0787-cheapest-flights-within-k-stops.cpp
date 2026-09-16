class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // Create adjacency list
        vector<vector<pair<int,int>>> adj(n);

        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // {destination, cost}
        vector<int> dist(n, 1e9);

        dist[src] = 0;

        // {stops, {node, cost}}
        queue<pair<int, pair<int,int>>> q;

        q.push({0, {src, 0}});

        while(!q.empty()) {

            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // More than k stops -> don't process
            if(stops > k)
                continue;

            for(auto iter : adj[node]) {

                int adjNode = iter.first;
                int edW = iter.second;

                if(cost + edW < dist[adjNode] && stops <= k) {

                    dist[adjNode] = cost + edW;

                    q.push({
                        stops + 1,
                        {adjNode, cost + edW}
                    });
                }
            }
        }

        if(dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};