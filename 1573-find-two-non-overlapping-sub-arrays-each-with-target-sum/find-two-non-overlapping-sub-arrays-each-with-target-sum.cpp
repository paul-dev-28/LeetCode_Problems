class Solution {
public:
    int minSumOfLengths(vector<int>& arr,int target)
    {
        int n=arr.size();
        vector<int> dp(n,1e9);
        int ans=1e9;
        int left=0,sum=0;
        int best=1e9;
        for(int right=0;right<n;right++)
        {
            sum+=arr[right];
            while(sum>target)
            {
                sum-=arr[left];
                left++;
            }
            if(sum==target)
            {
                int len=right-left+1;
                if(left>0 && dp[left-1]!=1e9)
                    ans=min(ans,len+dp[left-1]);
                best=min(best,len);
            }
            dp[right]=best;
        }
        return ans==1e9?-1:ans;
    }
};