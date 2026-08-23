class Solution {
public:
    bool isPalindromic(string s) {
        string s1="",s2="";
        for(int i=0;i<s.size();i++)
            {
                int l=s[i];
                while(l>=0)
                    {
                        s2+=to_string(l%2);
                        if (l==0)
                            break;
                        l/=2;
                    }
                reverse(s2.begin(),s2.end());
                s1+=s2;
                s2="";
            }
        int i=0,j=s1.size()-1;
        while(i<j)
            {
                if (s1[i]!=s1[j])
                    return false;
                i++;
                j--;
            }
        return true;
    }
};