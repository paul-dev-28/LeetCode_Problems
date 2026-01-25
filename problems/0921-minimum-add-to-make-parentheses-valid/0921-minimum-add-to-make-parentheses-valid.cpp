class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        stack<char> st1;
        for(int i=0;i<s.size();i++)
        {
            if (s[i]=='(')
                st.push(s[i]);
            if (s[i]==')' && !(st.empty()))
            {
                st.pop();
            }
            else if (s[i]==')' && (st.empty()))
                st1.push(s[i]);
        }
        
        return (st.size()+st1.size());
    }
};