class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++)
            a[i]={nums[i],i};
        sort(a.begin(),a.end());
        vector<int> pos(n);
        for(int i=0;i<n;i++)
            pos[a[i].second]=i;
        int lg=0;
        while((1<<lg)<=n)
            lg++;
        vector<vector<int>> up(n,vector<int>(lg));
        int r=0;
        for(int i=0;i<n;i++)
        {
            if(r<i)
                r=i;
            while(r+1<n &&
                  a[r+1].first-a[r].first<=maxDiff &&
                  a[r+1].first-a[i].first<=maxDiff)
                r++;
            up[i][0]=r;
        }
        for(int j=1;j<lg;j++)
        {
            for(int i=0;i<n;i++)
                up[i][j]=up[up[i][j-1]][j-1];
        }
        vector<int> ans;
        for(auto &v:queries)
        {
            int l=pos[v[0]];
            int r=pos[v[1]];
            if(l>r)
                swap(l,r);
            if(l==r)
            {
                ans.push_back(0);
                continue;
            }
            int cur=l;
            int cnt=0;
            for(int j=lg-1;j>=0;j--)
            {
                if(up[cur][j]<r)
                {
                    cur=up[cur][j];
                    cnt+=(1<<j);
                }
            }
            if(up[cur][0]>=r)
                ans.push_back(cnt+1);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};