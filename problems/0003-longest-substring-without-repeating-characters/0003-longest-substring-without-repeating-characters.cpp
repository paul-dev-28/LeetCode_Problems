class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256]={0};
        int l=0,r=0,maxi=0;
        while(r<s.size())
        {
            hash[s[r]]++;
            while(hash[s[r]]>1)
            {
                hash[s[l]]--;
                l++;
            }
            maxi=max(maxi,(r-l+1));
            r++;
        }
        return maxi;
    }
};