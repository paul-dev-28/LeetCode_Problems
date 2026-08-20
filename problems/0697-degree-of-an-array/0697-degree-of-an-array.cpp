class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> freq,first,last;
        int degree=0,ans=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
            if(!first.count(nums[i]))
                first[nums[i]]=i;
            last[nums[i]]=i;
            degree=max(degree,freq[nums[i]]);
        }
        for(auto &[x,f]:freq)
        {
            if(f==degree)
                ans=min(ans,last[x]-first[x]+1);
        }
        return ans;
    }
};