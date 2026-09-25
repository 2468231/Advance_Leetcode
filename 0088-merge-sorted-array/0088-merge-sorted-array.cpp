class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int low1 = 0;
        int low2 = 0;
        vector<int> ans;

        // Merge both arrays
        while (low1 < m && low2 < n) {
            if (nums1[low1] > nums2[low2]) {
                ans.push_back(nums2[low2]);
                low2++;
            }
            else if (nums2[low2] > nums1[low1]) {
                ans.push_back(nums1[low1]);
                low1++;
            }
            else {
                ans.push_back(nums1[low1]);
                ans.push_back(nums2[low2]);
                low1++;
                low2++;
            }
        }

        // Remaining elements of nums1
        while (low1 < m) {
            ans.push_back(nums1[low1]);
            low1++;
        }

        // Remaining elements of nums2
        while (low2 < n) {
            ans.push_back(nums2[low2]);
            low2++;
        }

        // Copy merged array back to nums1
        for (int i = 0; i < m + n; i++) {
            nums1[i] = ans[i];
        }
    }
};