class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        int i=discounts.size()-1;
        int j=prices.size()-1;
        double sum=0.0;
        while(i>=0 && j>=0)
        {
            sum+=(1.0*prices[j]*(100-discounts[i]))/100;
            i--;
            j--;
        }
        while(j>=0)
        {
            sum+=prices[j];
            j--;
        }
        return sum;
    }
};