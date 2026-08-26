class Solution {
public:
    int minDistance(string word1,string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> dp1(m+1,0);
        vector<int> dp2(m+1,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(word1[i]==word2[j])
                    dp1[j]=1+dp2[j+1];
                else
                    dp1[j]=max(dp2[j],dp1[j+1]);
            }
            dp2=dp1;
        }
        int lcs=dp1[0];
        return n+m-2*lcs;
    }
};