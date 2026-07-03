class Solution {
public:
  void dfs(int m, vector<int> & vis, vector<vector<int>> & adjLs){
      vis[m] = 1;
      for(auto it: adjLs[m]){
        if(vis[it] == 0){
            dfs(it, vis, adjLs);
        }
      }
  }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjLs(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int>vis(n);
        int count = 0;
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                count++;
                dfs(i, vis, adjLs);
            }
        }
     return count;
    }
};