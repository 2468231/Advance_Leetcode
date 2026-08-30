class Solution {
public:
    void fun(int i, vector<int>&ds, vector<vector<int>> &ans, int n, int k){
        if(i == n+1){
            if(ds.size() == k){
                ans.push_back(ds);
            }
            return;
        }

     ds.push_back(i);
    fun(i+1, ds, ans, n, k);

     ds.pop_back();
    fun(i+1, ds, ans, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        fun(1, ds, ans, n, k);
        return ans;
    }
};