class Solution
{
public:
    int countCompleteSubarrays(vector<int>& nums)
    {
        unordered_set<int> st(nums.begin(),nums.end());
        int need=st.size();
        unordered_map<int,int> freq;
        int j=0,ans=0,distinct=0;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
            if(freq[nums[i]]==1)
                distinct++;
            while(distinct==need)
            {
                ans+=nums.size()-i;
                freq[nums[j]]--;
                if(freq[nums[j]]==0)
                    distinct--;
                j++;
            }
        }
        return ans;
    }
};