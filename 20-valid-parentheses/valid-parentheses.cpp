class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int n=s.size();
        if (s[0]==')' || s[0]=='}' || s[0]==']' )
            return false;
        if ((s[0]=='(' || s[0]=='{' || s[0]=='[' ) && (n==1))
            return false;
        for(int i=0;i<n;i++)
        {
            if (s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else if (s[i]==')' && !st.empty())
            {
                char c=st.top();
                if (c!='(')
                    return false;
                else
                    st.pop();
            }
            else if (s[i]=='}' && !st.empty())
            {
                char c=st.top();
                if (c!='{')
                    return false;
                else
                    st.pop();
            }
            else if (s[i]==']' && !st.empty())
            {
                char c=st.top();
                if (c!='[')
                    return false;
                else
                    st.pop();
            }
            else if ((s[i]==')' || s[i]=='}' || s[i]==']') && (st.empty()))
                return false;
        }
        if (!st.empty())
            return false;
        return true;
    }
};