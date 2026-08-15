class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            result ^= x;

            if (x != 0) {
                hasNonZero = true;
            }
        }

        if (result != 0) {
            return n;
        }

        if (hasNonZero) {
            return n - 1;
        }

        return 0;
    }
};