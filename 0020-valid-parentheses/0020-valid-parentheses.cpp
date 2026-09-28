class Solution {
public:
    bool isValid(string s) {

        stack<int> st;
        int i = 0;

        if(s.size() == 1){
            return false;
        }

        while(i < s.size()){

            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
                i++;
            }

            else {

                if(st.empty()){
                    return false;
                }

                if(st.top() == '(' && s[i] == ')'){
                    st.pop();
                    i++;
                }
                else if(st.top() == '{' && s[i] == '}'){
                    st.pop();
                    i++;
                }
                else if(st.top() == '[' && s[i] == ']'){
                    st.pop();
                    i++;
                }
                else{
                    return false;
                }
            }
        }

        if(st.size() != 0){
            return false;
        }

        return true;
    }
};