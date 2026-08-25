class Solution {
public:
    int minimumDifference(vector<int>& nums)
    {
        int m=nums.size()/2;
        int total=0;
        for(int x:nums)
            total+=x;
        vector<vector<int>> left(m+1),right(m+1);
        for(int mask=0;mask<(1<<m);mask++)
        {
            int sum1=0,sum2=0,cnt=0;
            for(int j=0;j<m;j++)
            {
                if(mask&(1<<j))
                {
                    sum1+=nums[j];
                    sum2+=nums[j+m];
                    cnt++;
                }
            }
            left[cnt].push_back(sum1);
            right[cnt].push_back(sum2);
        }
        for(int i=0;i<=m;i++)
            sort(right[i].begin(),right[i].end());
        int ans=INT_MAX;
        for(int cnt=0;cnt<=m;cnt++)
        {
            int need=m-cnt;
            for(int x:left[cnt])
            {
                int target=total/2-x;
                auto it=lower_bound(right[need].begin(),right[need].end(),target);
                if(it!=right[need].end())
                {
                    int selected=x+*it;
                    ans=min(ans,abs(total-2*selected));
                }
                if(it!=right[need].begin())
                {
                    --it;
                    int selected=x+*it;
                    ans=min(ans,abs(total-2*selected));
                }
            }
        }
        return ans;
    }
};