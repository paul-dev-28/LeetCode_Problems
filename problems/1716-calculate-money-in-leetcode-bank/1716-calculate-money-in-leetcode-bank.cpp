class Solution {
public:
    int totalMoney(int n) {
        int money=1,amount=1,t=0,c=0;
        for(int i=1;i<=n;i++)
        {
            t=t+amount;
            amount++;
            c++;
            if (c==7)
            {
                c=0;
                money++;
                amount=money;
            }
        }
        return t;
    }
};