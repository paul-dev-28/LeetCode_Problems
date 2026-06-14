class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m=units.size();
        int n=units[0].size();
        
        long long ans=0LL;
        if (n==1)
        {
            for(auto &row :units)
                    ans+=row[0];
            return ans;
        }
        long long sumsecond=0;
        int globalmin=INT_MAX;
        int minsecond=INT_MAX;
        for(auto &row :units)
            {
                sort(row.begin(),row.end());
                int first=row[0];
                int second=row[1];
                globalmin=min(globalmin,first);
                sumsecond+=second;
                minsecond=min(minsecond,second);
            }
        ans=sumsecond+globalmin-minsecond;
        return ans;
    }
};