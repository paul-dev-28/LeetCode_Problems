class Solution {
public:
    long long minimumCost(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        string s=to_string(nums[n/2]);
        int len=s.size();
        long long p=stoll(s.substr(0,(len+1)/2));
        vector<long long> cand;
        for(long long x=max(1LL,p-1);x<=p+1;x++)
        {
            string left=to_string(x);
            string t=left;
            int i=(len%2)?left.size()-2:left.size()-1;
            for(;i>=0;i--)
                t+=left[i];
            cand.push_back(stoll(t));
        }
        cand.push_back(pow(10,len)+1);
        cand.push_back(pow(10,len-1)-1);
        long long ans=LLONG_MAX;
        for(long long x:cand)
        {
            if(x<=0)
                continue;
            long long cost=0;
            for(int v:nums)
                cost+=abs((long long)v-x);
            ans=min(ans,cost);
        }
        return ans;
    }
};