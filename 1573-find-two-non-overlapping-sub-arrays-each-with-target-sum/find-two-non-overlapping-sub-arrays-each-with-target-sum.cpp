class Solution
{
public:
    int minSumOfLengths(vector<int>& arr,int target)
    {
        int n=arr.size(),ans=1e9;
        vector<int> best(n,1e9);
        unordered_map<long long,int> mp;
        mp[0]=-1;
        long long sum=0;
        int cur=1e9;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(mp.count(sum-target))
            {
                int j=mp[sum-target]+1;
                int len=i-j+1;
                if(j>0 && best[j-1]!=1e9)
                    ans=min(ans,best[j-1]+len);
                cur=min(cur,len);
            }
            best[i]=cur;
            mp[sum]=i;
        }
        return ans==1e9?-1:ans;
    }
};