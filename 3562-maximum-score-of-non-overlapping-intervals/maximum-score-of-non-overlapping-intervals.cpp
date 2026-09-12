class Solution {
public:
    struct State {
        long long sum=0;
        vector<int>v;
    };
    bool better(State a,State b)
    {
        if(a.sum!=b.sum)
            return a.sum>b.sum;
        return lexicographical_compare(a.v.begin(),a.v.end(),b.v.begin(),b.v.end());
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>a(n);
        for(int i=0;i<n;i++)
            a[i]={intervals[i][0],intervals[i][1],intervals[i][2],i};
        sort(a.begin(),a.end(),[](vector<int>&x,vector<int>&y) {
            return x[1]<y[1];
        });
        vector<int>ends(n);
        for(int i=0;i<n;i++)
            ends[i]=a[i][1];
        vector<int>p(n);
        for(int i=0;i<n;i++)
            p[i]=lower_bound(ends.begin(),ends.begin()+i,a[i][0])-ends.begin();
        vector<vector<State>>dp(n+1,vector<State>(5));
        for(int i=1;i<=n;i++)
        {
            for(int k=1;k<=4;k++)
            {
                dp[i][k]=dp[i-1][k];
                State cur=dp[p[i-1]][k-1];
                cur.sum+=a[i-1][2];
                cur.v.push_back(a[i-1][3]);
                sort(cur.v.begin(),cur.v.end());
                if(better(cur,dp[i][k]))
                    dp[i][k]=cur;
            }
        }
        return dp[n][4].v;
    }
};