class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(k>=n/2)
        {
            int ans=0;
            for(int i=1;i<n;i++)
            {
                if(prices[i]>prices[i-1])
                    ans+=prices[i]-prices[i-1];
            }
            return ans;
        }
        vector<int> buy(k+1,INT_MIN);
        vector<int> sell(k+1,0);
        for(int x:prices)
        {
            for(int j=1;j<=k;j++)
            {
                buy[j]=max(buy[j],sell[j-1]-x);
                sell[j]=max(sell[j],buy[j]+x);
            }
        }
        return sell[k];
    }
};