class Solution {
public:
    vector<vector<int>> factors;
    vector<int> getFactors(int x)
    {
        vector<int>v;
        for(int p=2;1LL*p*p<=x;p++)
        {
            if(x%p==0)
            {
                v.push_back(p);
                while(x%p==0)
                    x/=p;
            }
        }
        if(x>1)
            v.push_back(x);
        return v;
    }
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        factors.resize(n);
        for(int i=0;i<n;i++)
            factors[i]=getFactors(nums[i]);
        int ans=min(2,n);
        for(int i=0;i<n;i++)
        {
            unordered_set<int>used;
            for(int j=i;j<n;j++)
            {
                bool ok=true;
                for(int p:factors[j])
                {
                    if(used.count(p))
                    {
                        ok=false;
                        break;
                    }
                }
                if(!ok)
                    break;
                for(int p:factors[j])
                    used.insert(p);
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};