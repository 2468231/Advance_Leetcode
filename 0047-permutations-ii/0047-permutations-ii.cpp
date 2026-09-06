class Solution {
public:

    void fun(vector<int>& nums,
             vector<int>& used,
             vector<int>& ds,
             vector<vector<int>>& ans) {

        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            // Skip duplicate choices at the same level
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            used[i] = 1;
            ds.push_back(nums[i]);

            fun(nums, used, ds, ans);

            ds.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;

        vector<int> used(nums.size(), 0);

        sort(nums.begin(), nums.end());

        fun(nums, used, ds, ans);

        return ans;
    }
};