class Solution {
public:
    void fun(vector<bool> &used, vector<int> &ds, vector<vector<int>>&ans, vector<int>& nums){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!used[i]){
                used[i] = true;
                ds.push_back(nums[i]);
                fun(used, ds, ans, nums);

                used[i] = false;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        vector<bool> used(nums.size(), false);
        fun(used, ds, ans, nums);
        return ans;
    }
};