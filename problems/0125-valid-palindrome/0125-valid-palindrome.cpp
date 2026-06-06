class Solution {
public:
    bool palindrome(int i,int n, vector<char> &s1)
    {
        if (i>=n/2)
            return true;
        if (s1[i]!=s1[n-i-1])
            return false;
        return palindrome(i+1,n,s1);
    }
    bool isPalindrome(string s) {
        int i;
        vector<char> s2;
        for( i=0;i<s.size();)
        {
            if (s[i]>='A' && s[i]<='Z')
                s[i]=(char)tolower(s[i]);
            if (((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')))
                s2.push_back(s[i]);
            
                i++;
        }
        return palindrome(0,s2.size(),s2);
    }
    
};