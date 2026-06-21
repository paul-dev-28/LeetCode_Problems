class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int c=0,sum=0;
        sort(costs.begin(),costs.end());
        for(int i=0;i<costs.size();i++)
        {
            if (costs[i]>coins)
            {
                break;
            }
            coins-=costs[i];
            c++;
        }
        return c;
    }
};