class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int left=0,right=0,maxFreq=0,ans=0;
        while(right<s.size())
        {
            freq[(s[right]-'A')]++;
            maxFreq=max(maxFreq,freq[(s[right]-'A')]);
            if((((right-left)+1)-maxFreq)>k)
            {
                freq[(s[left]-'A')]--;
                left++;
            }
            if ((right-left-maxFreq+1)<=k)
                ans=max(ans,((right-left)+1));
            right++;
        }
        return ans;
    }
};