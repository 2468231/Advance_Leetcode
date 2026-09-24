class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] < 10){
                if(i == nums[i]){
                    return i;
                }
                else{
                    continue;
                }
            }
            else{
            int sum = 0;
            while(nums[i] > 0){
              int  digi = nums[i] % 10;
                sum += digi;
                nums[i] /= 10;
            }
            if(i == sum){
               return i;
            }
            }
        }
        return -1;
    }
};