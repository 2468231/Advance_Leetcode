class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
       vector<vector<int>> adj(n);
       
        for(auto it: pre){
        adj[it[1]].push_back(it[0]);
       }
       

       vector<int> inde(n, 0);
       for(int i=0; i<n; i++){
        for(auto it: adj[i]){
            inde[it]++;
        }
       }

       queue<int> q;
      for(int i=0; i<n; i++){
        if(inde[i] == 0){
            q.push(i);
        }
      }
     
    vector<int> topo;

while(q.size()){
    int node = q.front();
    topo.push_back(node);
    q.pop();
    for(auto it: adj[node]){
        inde[it]--;

        if(inde[it] == 0){
            q.push(it);
        }
    }
}
if(topo.size() == n){
    return topo;
}
return { };
    }
};