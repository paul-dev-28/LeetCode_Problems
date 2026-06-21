class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size(),ans=0;;
        long long sub=0LL;
        for(int i=0;i<n;i++)
        {
            long long sum=0LL;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                long long sum2=sum;
                int last=sum2%10;
                while(sum2>=10)
                    sum2/=10;
                int first=sum2;
                if (first==x && last==x)
                    ans++;
            }
        }
        return ans;
    }
};