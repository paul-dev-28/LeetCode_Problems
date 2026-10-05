class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> st;
        st.push_back(0);
        for(char c:s)
        {
            if(c=='(')
                st.push_back(0);
            else
            {
                int x=st.back();
                st.pop_back();
                st.back()+=x==0?1:2*x;
            }
        }
        return st.back();
    }
};