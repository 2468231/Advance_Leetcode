class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        map<char, char> mp;    // s -> t
        map<char, char> mp2;   // t -> s

        mp[s[0]] = t[0];
        mp2[t[0]] = s[0];

        for(int i = 1; i < s.size(); i++){
            char ch1 = s[i];
            char ch2 = t[i];

            // check s -> t
            if(mp.find(ch1) != mp.end()){
                if(mp[ch1] != ch2){
                    return false;
                }
            }
            else{
                mp[ch1] = ch2;
            }

            // check t -> s (IMPORTANT FIX)
            if(mp2.find(ch2) != mp2.end()){
                if(mp2[ch2] != ch1){
                    return false;
                }
            }
            else{
                mp2[ch2] = ch1;
            }
        }

        return true;
    }
};