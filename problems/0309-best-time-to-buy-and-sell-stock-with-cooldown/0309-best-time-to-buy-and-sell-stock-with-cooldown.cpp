class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=-prices[0];
        int sell=0;
        int cool=0;
        for(int i=1;i<prices.size();i++)
        {
            int b=buy;
            int s=sell;
            int c=cool;
            buy=max(b,c-prices[i]);
            sell=max(s,b+prices[i]);
            cool=s;
        }
        return max(sell,cool);
    }
};