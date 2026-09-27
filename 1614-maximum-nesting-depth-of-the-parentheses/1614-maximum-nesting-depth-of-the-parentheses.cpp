class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int maxi = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
               count += 1;
               maxi = max(maxi, count);
            }
            else if(s[i] == ')'){
                count -= 1;
            }
        }

        return maxi;
    }
};