class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        set<int>s;
        for(int i=0; i<n; i++){
            if(nums[i] % k == 0){
                s.insert(nums[i]);
            }
        }
        int i=k;
        int it = *s.begin();
        if(it != k){
         return k;
        }
        
        for(int x : s){
            if(x != i){
               return i;
            }
            i += k;
        }
    return i;
    }
};