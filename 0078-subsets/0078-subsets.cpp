class Solution {
public:
    void fun(int i, vector<int>& ds, vector<vector<int>>&ans, vector<int> & nums, int n){
        if(i == n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        fun(i+1, ds, ans, nums, n);

        ds.pop_back();
        fun(i+1, ds, ans, nums, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> ds;
        fun(0, ds, ans, nums, nums.size());
        return ans;
    }
};