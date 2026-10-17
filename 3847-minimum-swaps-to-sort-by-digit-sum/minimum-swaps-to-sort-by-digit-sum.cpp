class Solution {
public:
    int digitSum(int x)
    {
        int sum=0;
        while(x>0)
        {
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> a=nums;
        sort(a.begin(),a.end(),[&](int x,int y)
        {
            int s1=digitSum(x),s2=digitSum(y);
            if(s1==s2)
                return x<y;
            return s1<s2;
        });
        unordered_map<int,int> pos;
        for(int i=0;i<n;i++)
            pos[a[i]]=i;
        vector<bool> vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i] || pos[nums[i]]==i)
                continue;
            int j=i,len=0;
            while(!vis[j])
            {
                vis[j]=true;
                j=pos[nums[j]];
                len++;
            }
            ans+=len-1;
        }
        return ans;
    }
};