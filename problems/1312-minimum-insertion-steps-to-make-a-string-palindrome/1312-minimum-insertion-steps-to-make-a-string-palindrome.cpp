class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        string str=s;
        reverse(str.begin(),str.end());
        vector<int> dp1(n+1,0);
        vector<int> dp2(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(s[i]==str[j])
                    dp1[j]=1+dp2[j+1];
                else
                    dp1[j]=max(dp2[j],dp1[j+1]);
            }
            dp2=dp1;
        }
        return n-dp1[0];
    }
};