class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0,j=0,maxi=0;
        unordered_map<char,int> mpp;
        while(j<s.size())
        {
            mpp[s[j]]++;
            if (mpp[s[j]]>2)
            {
                while(mpp[s[j]]>2)
                {
                    mpp[s[i]]--;
                    i++;
                }
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};