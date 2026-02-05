class Solution {
public:
    string reverseWords(string s) {
        s=s+' ';
        int n=s.size();
        string s1="";
        string s2="";
        for(int i=0;i<n;i++)
        {
            if (s[i]!=' ')
                s1=s[i]+s1;
            else if(i==(n-1))
            {
                 s2=s2+s1;
                 s1="";
                 break;
            }  
            else
            {
                 s2=s2+s1+' ';
                 s1="";
            }   
        }
        return s2;
    }
};