class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget)
    {
        int n=items.size();
        int minPrice=INT_MAX;
        vector<int> benefit(n,1);

        for(int i=0;i<n;i++)
        {
            minPrice=min(minPrice,items[i][1]);
            for(int j=0;j<n;j++)
            {
                if(i!=j && items[j][0]%items[i][0]==0)
                    benefit[i]++;
            }
        }

        vector<int> dp(budget+1,INT_MIN);
        dp[0]=0;

        for(int i=0;i<n;i++)
        {
            int price=items[i][1];
            for(int c=budget;c>=price;c--)
            {
                if(dp[c-price]!=INT_MIN)
                    dp[c]=max(dp[c],dp[c-price]+benefit[i]);
            }
        }

        int ans=0;
        for(int c=0;c<=budget;c++)
        {
            if(dp[c]!=INT_MIN)
                ans=max(ans,dp[c]+(budget-c)/minPrice);
        }

        return ans;
    }
};