class Solution {
public:
    int countBinarySubstrings(string s) {
        int t=0,c=1;
        vector<int> no;
        for(int i=1;i<s.size();i++)
        {
            if (s[i-1]==s[i])
                c++;
            else
            {
                no.push_back(c);
                c=1;
            }
        }
        no.push_back(c);
        for(int i=0;i<no.size()-1;i++)
        {
            t+=min(no[i+1],no[i]);
        }
        return t;
    }
};