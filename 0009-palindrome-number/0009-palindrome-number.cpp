class Solution {
public:
    bool isPalindrome(int x) {
        string st = to_string(x);
        int n = st.size();
        int low = 0;
        int high = n-1;
        while(low < high){
            if(st[low] != st[high]){
              return false;
            }
            low++;
            high--;
        }
    return true;
    }
};