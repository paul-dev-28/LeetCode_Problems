class Solution {
public:
    long long countBeautifulPairs(vector<int>& nums) {
        int n=nums.size();
        int cnt[10]={0};
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            int last=x%10;
            while(x>=10)
                x/=10;
            int first=x;
            for(int j=1;j<=9;j++)
            {
                if(gcd(j,last)==1)
                    ans+=cnt[j];
            }
            cnt[first]++;
        }
        return ans;
    }
};