class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        sort(bulbs.begin(),bulbs.end());
        vector<int> on;
        int n=bulbs.size();
        if (n==1)
            return bulbs;
        int i=0,c=1;
        for(int i=0;i<n;)
        {
            while(i<n-1 && bulbs[i+1]==bulbs[i])
            {
                c++;
                i++;
            }
            if (c%2==1)
                on.push_back(bulbs[i]);
            i++;
            c=1;
        }
        return on;
    }
};