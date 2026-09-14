class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);
        int ans=0,flag=0;
        for(auto &[x,v]:mp)
        {
            if(v.size()>=3)
            {
                int diff=v[1]-v[0];
                for(int i=2;i<v.size();i++)
                {
                    if (v[i]-v[i-1]!=diff)
                    {
                        flag=1;
                        break;
                    }
                    
                }
                if (flag==0)
                    ans++;
                flag=0;
            }
        }
        return ans;
    }
};