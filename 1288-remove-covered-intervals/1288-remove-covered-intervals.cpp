class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[0] == b[0]){
                return a[1] > b[1];  //For Edge case, You think that edge case
            }
            return a[0] < b[0];
        });

        int n = intervals.size();
        int maxel = intervals[0][1];
        int count = n;
        for(int i=1; i<n; i++){
            if(intervals[i][1] <= maxel){
                count--;
            }
            else{
                maxel = max(maxel, intervals[i][1]);
            }
        }
    return count;
    }
};