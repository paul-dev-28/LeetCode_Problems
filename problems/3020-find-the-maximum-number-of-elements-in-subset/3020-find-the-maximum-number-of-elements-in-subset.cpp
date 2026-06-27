class Solution
{
public:
    int maximumLength(vector<int>& nums)
    {
        unordered_map<long long,int> freq;
        for(int x:nums)
            freq[x]++;
        int ans=0;
        if(freq.count(1))
        {
            int cnt=freq[1];
            ans=max(ans,(cnt%2)?cnt:cnt-1);
        }
        for(auto &[x,c]:freq)
        {
            if(x==1)
                continue;
            long long cur=x;
            int len=0;
            while(freq.count(cur))
            {
                if(freq[cur]>=2)
                {
                    len+=2;
                    if(cur>1000000000LL/cur)
                        break;
                    cur*=cur;
                }
                else
                {
                    len++;
                    break;
                }
            }
            if((len&1)==0)
                len--;
            ans=max(ans,len);
        }
        return ans;
    }
};