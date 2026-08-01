class Solution {
public:
    int countValidPrefixes(string s) {
        int c=0,z=0,o=0;
        for(int i=0;i<s.size();i++)
        {
            if (s[i]=='0')
                z++;
            else if (s[i]=='1')
                o++;
            if (abs(z-o)<=1)
                c++;
        }
        return c;
    }
};