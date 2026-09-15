class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
         int n = nums.size();

         int low = 1;
         int high = *max_element(nums.begin(), nums.end());

         while(low <= high){
            int mid = (int)(low+high)/2;

            long long ans = 0;
            for(int i = 0; i < n; i++) {
                ans += (nums[i] + mid - 1) / mid;
            }

            if(ans > threshold){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
         }
         return low;
    }
};