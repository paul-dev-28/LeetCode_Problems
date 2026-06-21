class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        long long low = 1LL,high=1000000000LL,T=0LL;
        while (low<=high)
        {
            long long mid=low+(high-low)/2;
            long long cnt=0;
            int n=value.size();
            for (int i=0;i<n;i++)
            {
                long long a=value[i];
                long long d=decay[i];
                if (a<mid)
                    continue;
                cnt+=(a-mid)/d+1;
                if (cnt>(long long)4e18)
                    break;
            }
            if (cnt>=m)
            {
                T=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        long long used = 0;
        __int128 total = 0;
        int n=value.size();
        for (int i=0;i<n;i++)
        {
            long long a = value[i];
            long long d = decay[i];
            if (a<=T) 
                continue;
            long long k=(a-(T+1))/d+1;
            used+=k;
            __int128 sum=(__int128)k*(2LL*a-(k-1)*d)/2;
            total+=sum;
        }
        total+=(__int128)(m-used)*T;
        return (long long)(total%(1000000000+7));
    }
};