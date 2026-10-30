class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int low1 = 0;
        int low2 = 0;
        vector<int> temp;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                while(low1 < n){
                    if(nums[low1] < 0){
                        low1++;
                    } 
                    else{
                       temp.push_back(nums[low1]);
                       low1++;
                       break; 
                    }
                }
            }
            else{
                while(low2 < n){
                    if(nums[low2] > 0){
                        low2++;
                    }
                    else{
                        temp.push_back(nums[low2]);
                        low2++;
                        break;
                    }
                }
            }
        }
        return temp;
    }
};