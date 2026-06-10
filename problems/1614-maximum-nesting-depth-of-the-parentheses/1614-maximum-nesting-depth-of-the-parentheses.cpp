class Solution {
public:
    int maxDepth(string s) {
        int len=0,maxi=0;
        for(int i=0;i<s.size();i++)
        {
            if (s[i]=='(')
            {
                len++;
                maxi=max(len,maxi);
            }    
            if (s[i]==')')
            {
                len--;
            }
        }
        return maxi;
    }
};