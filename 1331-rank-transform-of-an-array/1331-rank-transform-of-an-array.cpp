class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n = arr.size();

        if(n == 0) return {};

        vector<int> original = arr;

        sort(arr.begin(), arr.end());

        map<int, int> mp;

        int rank = 1;
        mp[arr[0]] = rank;

        for(int i = 1; i < n; i++) {
            if(arr[i] != arr[i - 1]) {
                rank++;
                mp[arr[i]] = rank;
            }
        }

        vector<int> ans;

        for(int x : original) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};