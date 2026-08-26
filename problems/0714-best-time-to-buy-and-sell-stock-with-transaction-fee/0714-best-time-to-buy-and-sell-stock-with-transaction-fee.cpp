class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy=-prices[0];
        int sell=0;
        for(int i=1;i<prices.size();i++)
        {
            int b=buy;
            int s=sell;
            buy=max(b,s-prices[i]);
            sell=max(s,b+prices[i]-fee);
        }
        return sell;
    }
};