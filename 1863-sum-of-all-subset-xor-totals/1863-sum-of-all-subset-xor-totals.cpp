class Solution {
public:
void fun(int i, int ds, vector<int>& nums, int & result, int n) {
    if (i == n) {
        result += ds;
        return;
    }

    // Take
    ds ^= nums[i];
    fun(i + 1, ds, nums, result, n);

    // Undo
    ds ^= nums[i];

    // Don't take
    fun(i + 1, ds, nums, result, n);
}
    int subsetXORSum(vector<int>& nums) {
       int result = 0;
       fun(0, 0, nums, result, nums.size());
       return result;
    }
};