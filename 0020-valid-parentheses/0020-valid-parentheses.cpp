class Solution {
public:
    bool isValid(string s) {
        stack <char> st; //for opening brackets
        for (int i = 0; i < s.length(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char ch = st.top();
                st.pop();
                if((s[i]==')' && ch!='(') || (s[i]=='}' && ch!='{') || (s[i]==']' && ch!='['))
                {
                    return false;
                }
            }
        }
        return st.empty(); //To ensure no unmatched opening brackets are left in the stack after parsing the string. If anything's left then invalid.
    }
};