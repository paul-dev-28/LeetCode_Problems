class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++)
            a.push_back({aliceValues[i]+bobValues[i],i});
        sort(a.rbegin(),a.rend());
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
                x+=aliceValues[a[i].second];
            else
                y+=bobValues[a[i].second];
        }
        if(x>y)
            return 1;
        if(x<y)
            return -1;
        return 0;
    }
};